#include <types.h>
#include <leds.h>
#include <switches.h>
#include <string.h>
#include <debug.h>
#include <armv7m.h>


/*
Packet Format:
Request:
| uint32_t reqNum | uint32_t cmdCode | variables params... |
Reply:
| uint32_t reqNum | uint32_t cmdCode | result............. |
*/


// cmdCode
#define CMD_TEST       						0x00000001
#define CMD_TEST_PARAM 						0x00000002
#define CMD_SW_GET     						0x00000003
#define CMD_LEDS_OFF   						0x00000004
#define CMD_LEDS_RED   						0x00000005
#define CMD_LEDS_GREEN 						0x00000006
#define CMD_GET_DEBUG_BUF 					0x00000007
#define CMD_SET_DEBUG_BUF 					0x00000008
#define CMD_FM_SEND_DATA					0x10000009
#define CMD_FM_RECV_DATA					0x1000000a


// params[0]
// ret[9]
void cmdTest(uint8_t* params, uint8_t* ret)
{
	ret[0] = '[';
	ret[1] = 'T';
	ret[2] = 'E';
	ret[3] = 'S';
	ret[4] = 'T';
	ret[5] = ' ';
	ret[6] = 'O';
	ret[7] = 'K';
	ret[8] = ']';
}

// params[16]
// ret[27]
void cmdTestParam(uint8_t* params, uint8_t* ret)
{
	ret[0] = 'T';
	ret[1] = 'E';
	ret[2] = 'S';
	ret[3] = 'T';
	ret[4] = ' ';
	ret[5] = 'P';
	ret[6] = 'A';
	ret[7] = 'R';
	ret[8] = 'A';
	ret[9] = 'M';
	ret[10] = ':';
	memcpy(ret + 11, params, 16);
}

// params[0]
// ret[1]
void cmdSwGet(uint8_t* params, uint8_t* ret)
{
	ret[0] = switch_dbg_is_set() ? '\xF1' : '\xF0';
}

// params[0]
// ret[1]
void cmdLedsOff(uint8_t* params, uint8_t* ret)
{
//	led_red_power_off();
//	led_green_power_off();
//	ret[0] = '\xAA';
}

// params[0]
// ret[1]
void cmdLedsRed(uint8_t* params, uint8_t* ret)
{
//	led_red_power_on();
//	led_green_power_off();
//	ret[0] = '\xBB';
}

// params[0]
// ret[1]
void cmdLedsGreen(uint8_t* params, uint8_t* ret)
{
//	led_red_power_off();
//	led_green_power_on();
//	ret[0] = '\xCC';
}

// params[1]
// ret[32]
void cmdGetDebugBuf(uint8_t* params, uint8_t* ret)
{
	switch (params[0])
	{
	case 1:
		memcpy(ret, debug_buf1, DEBUG_BUF_SIZE);
		break;

	case 2:
		memcpy(ret, debug_buf2, DEBUG_BUF_SIZE);
		break;

	case 3:
		memcpy(ret, debug_buf3, DEBUG_BUF_SIZE);
		break;

	case 0:
	default:
		memcpy(ret, debug_buf0, DEBUG_BUF_SIZE);
		break;
	}
}

// params[33]
// ret[1]
void cmdSetDebugBuf(uint8_t* params, uint8_t* ret)
{
	switch (params[0])
	{
	case 1:
		memcpy(debug_buf1, params+1, DEBUG_BUF_SIZE);
		break;

	case 2:
		memcpy(debug_buf2, params+1, DEBUG_BUF_SIZE);
		break;

	case 3:
		memcpy(debug_buf3, params+1, DEBUG_BUF_SIZE);
		break;

	case 0:
	default:
		memcpy(debug_buf0, params+1, DEBUG_BUF_SIZE);
		break;
	}

	ret[0] = '\xDD';
}

// params[9]
// ret[1]
void cmdFmSendData(uint8_t* params, uint8_t* ret)
{
//	uint32_t sz = params[0];
//	if (!(sz >= 1 && sz <= 8))
//		sz = 1;
//	si4705_i2c_send(params + 1, sz);
//	ret[0] = '\x77';
}

// params[1]
// ret[16]
void cmdFmRecvData(uint8_t* params, uint8_t* ret)
{
//	uint32_t sz = params[0];
//	if (!(sz >= 1 && sz <= 16))
//		sz = 1;
//	si4705_i2c_recv(ret, sz);
}


void processCommand(uint32_t cmdCode, uint8_t* params, uint8_t* ret)
{
	switch (cmdCode)
	{
	case CMD_TEST:
		cmdTest(params, ret);
		break;

	case CMD_TEST_PARAM:
		cmdTestParam(params, ret);
		break;

	case CMD_SW_GET:
		cmdSwGet(params,ret);
		break;

	case CMD_LEDS_OFF:
		cmdLedsOff(params, ret);
		break;

	case CMD_LEDS_RED:
		cmdLedsRed(params, ret);
		break;

	case CMD_LEDS_GREEN:
		cmdLedsGreen(params, ret);
		break;

	case CMD_GET_DEBUG_BUF:
		cmdGetDebugBuf(params, ret);
		break;

	case CMD_SET_DEBUG_BUF:
		cmdSetDebugBuf(params, ret);
		break;
	}
}


void processCommandDPC(uint32_t cmdCode, uint8_t* params, uint8_t* ret)
{
	switch (cmdCode)
	{
	case CMD_FM_SEND_DATA:
		cmdFmSendData(params, ret);
		break;

	case CMD_FM_RECV_DATA:
		cmdFmRecvData(params, ret);
		break;
	}
}



static volatile uint8_t ret_buf[64];
static volatile uint8_t dpc_req_buf[64];
static volatile uint16_t dpc_is_run;

void DPCDispatch(void)
{
	if (dpc_is_run)
	{
		memset((void*)ret_buf, 0, 64);
		uint32_t cmdCode = *((uint32_t*)&dpc_req_buf[4]);
		uint8_t *params = (uint8_t*)&dpc_req_buf[8];
		uint8_t *ret = (uint8_t*)&ret_buf[8];
		memcpy((void*)ret_buf, (void*)dpc_req_buf, 8);
		processCommandDPC(cmdCode, params, ret);
		no_operation();
		dpc_is_run = 0;
	}
}


void GetInReport (uint8_t src[], uint32_t length)
{
	// Block ALL
	if (dpc_is_run)
		memset(src, 0, 64);
	else
		memcpy(src, (void*)ret_buf, sizeof(ret_buf));
	// UnBlock ALL
}

void SetOutReport (uint8_t dst[], uint32_t length)
{
	// Block ALL
/*
Packet Format:
Request:
| uint32_t reqNum | uint32_t cmdCode | variables params... |
Reply:
| uint32_t reqNum | uint32_t cmdCode | result............. |
*/

	memset((void*)ret_buf, 0, 64);

	uint32_t cmdCode = *((uint32_t*)&dst[4]);
	uint8_t *params = (uint8_t*)&dst[8];
	uint8_t *ret = (uint8_t*)&ret_buf[8];
	
	if (cmdCode & 0x10000000)
	{
		memcpy((void*)dpc_req_buf, dst, 64);
		dpc_is_run = 1;
	}
	else
	{
		memcpy((void*)ret_buf, dst, 8);
		processCommand(cmdCode, params, ret);
	}

	// UnBlock ALL
}

