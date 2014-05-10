#include "mydeviceproto.h"
#include <QDataStream>


MyDeviceProto::MyDeviceProto(MyDevice &mydev, QObject *parent)
    : QObject(parent), m_mydev(mydev), reqNum(0)
{
}

MyDeviceProto::~MyDeviceProto()
{
}

bool MyDeviceProto::processCommand(unsigned int cmdCode, const QByteArray &params, QByteArray &ret)
{
    QByteArray outBuf;
    QDataStream outData(&outBuf, QIODevice::Append);
    outData.setByteOrder(QDataStream::LittleEndian);
    outData << ++reqNum;
    outData << cmdCode;
    outData.setDevice(0);

    outBuf.append(params);

    bool res = false;

    if (m_mydev.sendData(outBuf))
    {
        QByteArray inBuf;
        bool go = true;
        while (go)
        {
            if (m_mydev.recvData(inBuf))
            {
                if (inBuf.left(8) == outBuf.left(8))  // Fast Resp or DpcDispatch
                {
                    go = false;
                    res = true;
                    inBuf.remove(0, 8);
                    ret = inBuf;
                }
            }
            else
                go = false;
        }
    }

    return res;
}

bool MyDeviceProto::cmdTest(QByteArray &retTest)
{
    const unsigned int CMD_TEST = 0x00000001;
    const int CMD_TEST_PARAMS = 0;
    const int CMD_TEST_RET = 9;
    QByteArray cmpTest = QByteArray::fromRawData("[TEST OK]", CMD_TEST_RET);
    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_TEST, QByteArray(CMD_TEST_PARAMS, '\0'), ret) &&
        ret.left(CMD_TEST_RET) == cmpTest)
    {
        retTest = ret.left(CMD_TEST_RET);
        res = true;
    }

    return res;
}

bool MyDeviceProto::cmdTestParam(const QByteArray &inTest, QByteArray &outTest)
{
    const unsigned int CMD_TEST_PARAM = 0x00000002;
    const int CMD_TEST_PARAM_PARAMS = 16;
    const int CMD_TEST_PARAM_RET = 27;

    bool res = false;

    QByteArray ret;

    if (inTest.size() == CMD_TEST_PARAM_PARAMS &&
        processCommand(CMD_TEST_PARAM, inTest, ret))
    {
        QByteArray cmpTest = QByteArray::fromRawData("TEST PARAM:", 11);
        cmpTest.append(inTest);
        Q_ASSERT(cmpTest.size() == CMD_TEST_PARAM_RET);

        if (ret.left(CMD_TEST_PARAM_RET) == cmpTest)
        {
            outTest = ret.left(CMD_TEST_PARAM_RET);
            res = true;
        }
    }

    return res;
}

/*


bool FmUsbTerminal::cmdSwGet(bool &isSw)
{
    const unsigned int CMD_SW_GET = 0x00000003;
    const int CMD_SW_GET_PARAMS = 0;
    const int CMD_SW_GET_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_SW_GET, QByteArray(CMD_SW_GET_PARAMS, '\0'), ret))
    {
        if (ret.left(CMD_SW_GET_RET) == QByteArray::fromHex("f0"))
        {
            isSw = false;
            res = true;
        }
        else if (ret.left(CMD_SW_GET_RET) == QByteArray::fromHex("f1"))
        {
            isSw = true;
            res = true;
        }
    }

    return res;
}

bool FmUsbTerminal::cmdLedsOff()
{
    const unsigned int CMD_LEDS_OFF = 0x00000004;
    const int CMD_LEDS_OFF_PARAMS = 0;
    const int CMD_LEDS_OFF_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_LEDS_OFF, QByteArray(CMD_LEDS_OFF_PARAMS, '\0'), ret) &&
        ret.left(CMD_LEDS_OFF_RET) == QByteArray::fromHex("aa"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdLedsRed()
{
    const unsigned int CMD_LEDS_RED = 0x00000005;
    const int CMD_LEDS_RED_PARAMS = 0;
    const int CMD_LEDS_RED_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_LEDS_RED, QByteArray(CMD_LEDS_RED_PARAMS, '\0'), ret) &&
        ret.left(CMD_LEDS_RED_RET) == QByteArray::fromHex("bb"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdLedsGreen()
{
    const unsigned int CMD_LEDS_GREEN = 0x00000006;
    const int CMD_LEDS_GREEN_PARAMS = 0;
    const int CMD_LEDS_GREEN_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_LEDS_GREEN, QByteArray(CMD_LEDS_GREEN_PARAMS, '\0'), ret) &&
        ret.left(CMD_LEDS_GREEN_RET) == QByteArray::fromHex("cc"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdGetDebugBuf(unsigned char bufNum, QByteArray &outBuf)
{
    const unsigned int CMD_GET_DEBUG_BUF = 0x00000007;
    const int CMD_GET_DEBUG_BUF_PARAMS = 1;
    const int CMD_GET_DEBUG_BUF_RET = 32;

    bool res = false;

    QByteArray ret;
    QByteArray in(CMD_GET_DEBUG_BUF_PARAMS, bufNum);

    if (bufNum <= 3 &&
        processCommand(CMD_GET_DEBUG_BUF, in, ret))
    {
        outBuf = ret.left(CMD_GET_DEBUG_BUF_RET);
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdSetDebugBuf(unsigned char bufNum, const QByteArray &inBuf)
{
    const unsigned int CMD_SET_DEBUG_BUF = 0x00000008;
    const int CMD_SET_DEBUG_BUF_PARAMS = 33;
    const int CMD_SET_DEBUG_BUF_RET = 1;

    bool res = false;

    QByteArray ret;
    QByteArray in(1, bufNum);
    in.append(inBuf);

    if (bufNum <= 3 &&
        in.size() == CMD_SET_DEBUG_BUF_PARAMS &&
        processCommand(CMD_SET_DEBUG_BUF, in, ret) &&
        ret.left(CMD_SET_DEBUG_BUF_RET) == QByteArray::fromHex("DD"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmSendData(const QByteArray &inData)
{
    const unsigned int CMD_FM_SEND_DATA = 0x10000009;
    const int CMD_FM_SEND_DATA_PARAMS = 9;
    const int CMD_FM_SEND_DATA_RET = 1;

    bool res = false;

    if (inData.size() >= 1 && inData.size() <= 8)
    {
        unsigned char sz = static_cast<unsigned char>(inData.size());
        QByteArray ret;
        QByteArray in(1, sz);
        in.append(inData);
        while (in.size() < CMD_FM_SEND_DATA_PARAMS)
            in.append('\0');
        Q_ASSERT(in.size() == CMD_FM_SEND_DATA_PARAMS);

        if (processCommand(CMD_FM_SEND_DATA, in, ret) &&
            ret.left(CMD_FM_SEND_DATA_RET) == QByteArray::fromHex("77"))
        {
            res = true;
        }
    }

    return res;
}

bool FmUsbTerminal::cmdFmRecvData(unsigned char dataSize, QByteArray &outData)
{
    const unsigned int CMD_FM_RECV_DATA = 0x1000000a;
    const int CMD_FM_RECV_DATA_PARAMS = 1;
    const int CMD_FM_RECV_DATA_RET = 16;

    bool res = false;

    QByteArray ret;
    QByteArray in(CMD_FM_RECV_DATA_PARAMS, dataSize);

    if (dataSize >= 1 && dataSize <= 16 &&
        processCommand(CMD_FM_RECV_DATA, in, ret))
    {
        outData = ret.left(CMD_FM_RECV_DATA_RET);
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmPowerUpAnalog()
{
    const unsigned int CMD_FM_POWER_UP_ANALOG = 0x1000000b;
    const int CMD_FM_POWER_UP_ANALOG_PARAMS = 0;
    const int CMD_FM_POWER_UP_ANALOG_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_POWER_UP_ANALOG, QByteArray(CMD_FM_POWER_UP_ANALOG_PARAMS, '\0'), ret) &&
        ret.left(CMD_FM_POWER_UP_ANALOG_RET) == QByteArray::fromHex("1b"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmPowerUpDigital()
{
    const unsigned int CMD_FM_POWER_UP_DIGITAL = 0x1000000c;
    const int CMD_FM_POWER_UP_DIGITAL_PARAMS = 0;
    const int CMD_FM_POWER_UP_DIGITAL_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_POWER_UP_DIGITAL, QByteArray(CMD_FM_POWER_UP_DIGITAL_PARAMS, '\0'), ret) &&
        ret.left(CMD_FM_POWER_UP_DIGITAL_RET) == QByteArray::fromHex("1c"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmPowerUpDigitalAnalog()
{
    const unsigned int CMD_FM_POWER_UP_DIGITAL_AND_ANALOG = 0x1000000d;
    const int CMD_FM_POWER_UP_DIGITAL_AND_ANALOG_PARAMS = 0;
    const int CMD_FM_POWER_UP_DIGITAL_AND_ANALOG_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_POWER_UP_DIGITAL_AND_ANALOG, QByteArray(CMD_FM_POWER_UP_DIGITAL_AND_ANALOG_PARAMS, '\0'), ret) &&
        ret.left(CMD_FM_POWER_UP_DIGITAL_AND_ANALOG_RET) == QByteArray::fromHex("1d"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmPowerDown()
{
    const unsigned int CMD_FM_POWER_DOWN = 0x1000000e;
    const int CMD_FM_POWER_DOWN_PARAMS = 0;
    const int CMD_FM_POWER_DOWN_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_POWER_DOWN, QByteArray(CMD_FM_POWER_DOWN_PARAMS, '\0'), ret) &&
        ret.left(CMD_FM_POWER_DOWN_RET) == QByteArray::fromHex("1e"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmSetProperty(unsigned short paddr, unsigned short pval)
{
    const unsigned int CMD_FM_SET_PROPERTY = 0x1000000f;
    const int CMD_FM_SET_PROPERTY_PARAMS = 4;
    const int CMD_FM_SET_PROPERTY_RET = 1;

    bool res = false;

    QByteArray in;
    in.append(QByteArray::fromRawData((char*)&paddr, 2));
    in.append(QByteArray::fromRawData((char*)&pval, 2));
    in.resize(CMD_FM_SET_PROPERTY_PARAMS);
    Q_ASSERT(in.size() == CMD_FM_SET_PROPERTY_PARAMS);
    QByteArray ret;

    if (processCommand(CMD_FM_SET_PROPERTY, in, ret) &&
        ret.left(CMD_FM_SET_PROPERTY_RET) == QByteArray::fromHex("1f"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmGetProperty(unsigned short paddr, unsigned short &pval)
{
    const unsigned int CMD_FM_GET_PROPERTY = 0x10000010;
    const int CMD_FM_GET_PROPERTY_PARAMS = 2;
    const int CMD_FM_GET_PROPERTY_RET = 2;

    bool res = false;

    QByteArray in;
    in.append(QByteArray::fromRawData((char*)&paddr, 2));
    in.resize(CMD_FM_GET_PROPERTY_PARAMS);
    Q_ASSERT(in.size() == CMD_FM_GET_PROPERTY_PARAMS);
    QByteArray ret;

    if (processCommand(CMD_FM_GET_PROPERTY, in, ret))
    {
        QByteArray outData = ret.left(CMD_FM_GET_PROPERTY_RET);
        pval = *((unsigned short*)(outData.data()));
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmGetRev(QByteArray &partNumber, QString &firmwareRev,
                                QByteArray &patchID, QString &componentRev,
                                QString &chipRev, QByteArray &cid)
{
    partNumber.clear();
    firmwareRev.clear();
    patchID.clear();
    componentRev.clear();
    chipRev.clear();
    cid.clear();

    const unsigned int CMD_FM_GET_REV = 0x10000011;
    const int CMD_FM_GET_REV_PARAMS = 0;
    const int CMD_FM_GET_REV_RET = 9;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_GET_REV, QByteArray(CMD_FM_GET_REV_PARAMS, '\0'), ret))
    {
        ret = ret.left(CMD_FM_GET_REV_RET);

        partNumber.append(ret[0]);
        firmwareRev.append(QChar(ret[1]));
        firmwareRev.append(QChar(ret[2]));
        patchID.append(ret[3]);
        patchID.append(ret[4]);
        componentRev.append(QChar(ret[5]));
        componentRev.append(QChar(ret[6]));
        chipRev.append(QChar(ret[7]));
        cid.append(ret[8]);

        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmGetIntStatus(unsigned char &intStatus)
{
    const unsigned int CMD_FM_GET_INT_STATUS = 0x10000012;
    const int CMD_FM_GET_INT_STATUS_PARAMS = 0;
    const int CMD_FM_GET_INT_STATUS_RET = 1;

    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_GET_INT_STATUS, QByteArray(CMD_FM_GET_INT_STATUS_PARAMS, '\0'), ret))
    {
        ret = ret.left(CMD_FM_GET_INT_STATUS_RET);
        intStatus = *(ret.data());
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmTuneFreq(unsigned short freq10KHz, unsigned char antCap)
{
    const unsigned int CMD_FM_TUNE_FREQ = 0x10000013;
    const int CMD_FM_TUNE_FREQ_PARAMS = 3;
    const int CMD_FM_TUNE_FREQ_RET = 1;

    bool res = false;

    QByteArray in;
    in.append(QByteArray::fromRawData((char*)&freq10KHz, 2));
    in.append(QByteArray::fromRawData((char*)&antCap, 1));
    in.resize(CMD_FM_TUNE_FREQ_PARAMS);
    Q_ASSERT(in.size() == CMD_FM_TUNE_FREQ_PARAMS);
    QByteArray ret;

    if (processCommand(CMD_FM_TUNE_FREQ, in, ret) &&
        ret.left(CMD_FM_TUNE_FREQ_RET) == QByteArray::fromHex("13"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmSeekStart(bool isUp, bool isWrap)
{
    const unsigned int CMD_FM_SEEK_START = 0x10000014;
    const int CMD_FM_SEEK_START_PARAMS = 2;
    const int CMD_FM_SEEK_START_RET = 1;

    bool res = false;

    QByteArray in;
    in.append(isUp ? '\x01' : '\x00');
    in.append(isWrap ? '\x01' : '\x00');
    in.resize(CMD_FM_SEEK_START_PARAMS);
    Q_ASSERT(in.size() == CMD_FM_SEEK_START_PARAMS);
    QByteArray ret;

    if (processCommand(CMD_FM_SEEK_START, in, ret) &&
        ret.left(CMD_FM_SEEK_START_RET) == QByteArray::fromHex("14"))
    {
        res = true;
    }

    return res;
}

bool FmUsbTerminal::cmdFmTuneStatus(bool isCancelSeek, bool isClearSTC,
                                    bool &isBandLimit, bool &isAFCRails, bool &isValidChannel,
                                    unsigned short &freq10KHz, unsigned char &rssi,
                                    unsigned char &snr, unsigned char &antcap)
{
    isBandLimit = false;
    isAFCRails = false;
    isValidChannel = false;
    freq10KHz = 0;
    rssi = 0;
    snr = 0;
    antcap = 0;

    const unsigned int CMD_FM_TUNE_STATUS = 0x10000015;
    const int CMD_FM_TUNE_STATUS_PARAMS = 2;
    const int CMD_FM_TUNE_STATUS_RET = 8;

    QByteArray in;
    in.append(isCancelSeek ? '\x01' : '\x00');
    in.append(isClearSTC ? '\x01' : '\x00');
    in.resize(CMD_FM_TUNE_STATUS_PARAMS);
    Q_ASSERT(in.size() == CMD_FM_TUNE_STATUS_PARAMS);
    QByteArray ret;

    bool res = false;

    if (processCommand(CMD_FM_TUNE_STATUS, in, ret))
    {
        ret = ret.left(CMD_FM_TUNE_STATUS_RET);

        isBandLimit = (ret[0] != '\0');
        isAFCRails = (ret[1] != '\0');
        isValidChannel = (ret[2] != '\0');
        freq10KHz = *((ushort*)(ret.data() + 3));
        rssi = ret[5];
        snr = ret[6];
        antcap = ret[7];
        res = true;
    }

    return res;
}

*/
