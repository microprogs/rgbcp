#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidget>
#include <QTableWidget>
#include <QScrollBar>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    modelMovie(this),
    isPlayMode(false)
{
    ui->setupUi(this);

    widgetLeds = new WidgetLeds(this);
    widgetTimeLine = new WidgetTimeLine(this);

    connect(widgetTimeLine, SIGNAL(timeLineFrameSelected(int)), this, SLOT(onTimeLineFrameSelected(int)));
    connect(widgetLeds, SIGNAL(ledFrameChanged()), this, SLOT(onLedFrameChanged()));

    ui->verticalLayoutWidgetLed->addWidget(widgetLeds);
    ui->verticalLayoutWidgetLed->addWidget(widgetTimeLine);

    setWindowTitle(tr("RGBCP GUI 1.0 TESTER"));

    onBtnNewMovie();
}

MainWindow::~MainWindow()
{
    delete widgetTimeLine;
    delete widgetLeds;
    delete ui;
}

void MainWindow::onBtnLoadFromFile()
{
    if (!isPlayMode)
    {
        QString openFileName = QFileDialog::getOpenFileName(this, "Open Movie File", ".", "Binary File (*.bin)");
        if (!openFileName.isNull())
        {
            if (QFile::exists(openFileName))
            {
                if (modelMovie.LoadFromFile(openFileName))
                {
                    if (modelMovie.frameCount() < 1)
                        modelMovie.insertFrameAfter(0);

                    widgetTimeLine->setFrameCount(modelMovie.frameCount());
                    selectFrame(0);
                    ui->statusBar->showMessage(QString("Movie Loaded From File: %1").arg(openFileName));
                }
                else
                {
                    QMessageBox::critical(this, "Load Movie File", "Can't load movie from file!");
                }
            }
            else
            {
                QMessageBox::critical(this, "Open Movie File", "This file don't exist!");
            }
        }
    }
}

void MainWindow::onBtnSaveToFile()
{
    if (!isPlayMode)
    {
        QString saveFileName = QFileDialog::getSaveFileName(this, "Save Movie File", ".", "Binary File (*.bin)");
        if (saveFileName.size() > 0)
        {
            if (modelMovie.SaveToFile(saveFileName))
            {
                ui->statusBar->showMessage(QString("Movie Saved To File: %1").arg(saveFileName));
            }
            else
            {
                QMessageBox::critical(this, "Save Movie File", "Can't save movie to file!");
            }
        }
    }
}

void MainWindow::onBtnNewMovie()
{
    if (!isPlayMode)
    {
        modelMovie.clearAll();
        modelMovie.insertFrameAfter(0);

        widgetTimeLine->setFrameCount(1);
        selectFrame(0);

        ui->statusBar->showMessage("New Movie");
    }
}

void MainWindow::onBtnPlayStopMovie()
{
    if (!isPlayMode)
        setPlayMode();
    else
        setEditMode();
}

void MainWindow::onBtnFrameClear()
{
    if (!isPlayMode)
    {
        const int frameIndex = widgetTimeLine->getFrameIndex();
        modelMovie.clearFrame(frameIndex);
        selectFrame(frameIndex);
    }
}

void MainWindow::onBtnFrameInsertBefore()
{
    if (!isPlayMode)
    {
        const int frameIndex = widgetTimeLine->getFrameIndex();
        const int frameCount = widgetTimeLine->getFrameCount();
        modelMovie.insertFrameBefore(frameIndex);
        widgetTimeLine->setFrameCount(frameCount + 1);
        selectFrame(frameIndex - 1);
    }
}

void MainWindow::onBtnFrameInsertAfter()
{
    if (!isPlayMode)
    {
        const int frameIndex = widgetTimeLine->getFrameIndex();
        const int frameCount = widgetTimeLine->getFrameCount();
        modelMovie.insertFrameAfter(frameIndex);
        widgetTimeLine->setFrameCount(frameCount + 1);
        selectFrame(frameIndex + 1);
    }
}

void MainWindow::onBtnFrameDelete()
{
    if (!isPlayMode)
    {
        const int frameIndex = widgetTimeLine->getFrameIndex();
        const int frameCount = widgetTimeLine->getFrameCount();

        if (frameCount <= 1)
        {
            onBtnFrameClear();
        }
        else
        {
            modelMovie.deleteFrame(frameIndex);
            widgetTimeLine->setFrameCount(frameCount - 1);
            selectFrame(frameIndex - 1);
        }
    }
}

void MainWindow::setPlayMode()
{
    if (!isPlayMode)
    {
        isPlayMode = true;
        ui->btnPlayStopMovie->setText("<<< STOP MOVIE >>>");

        widgetTimeLine->setReadOnlyMode(true);
        widgetLeds->setReadOnlyMode(true);

        ui->btnNewMovie->setEnabled(false);
        ui->btnSaveToFile->setEnabled(false);
        ui->btnLoadFromFile->setEnabled(false);
        ui->btnFrameClear->setEnabled(false);
        ui->btnFrameDelete->setEnabled(false);
        ui->btnFrameInsertBefore->setEnabled(false);
        ui->btnFrameInsertAfter->setEnabled(false);

        ui->statusBar->showMessage("Play Mode... Press Stop To Return To Edit Mode...");

        goTimer();
    }
}

void MainWindow::setEditMode()
{
    if (isPlayMode)
    {
        isPlayMode = false;
        ui->btnPlayStopMovie->setText("Play Movie");

        widgetTimeLine->setReadOnlyMode(false);
        widgetLeds->setReadOnlyMode(false);

        ui->btnNewMovie->setEnabled(true);
        ui->btnSaveToFile->setEnabled(true);
        ui->btnLoadFromFile->setEnabled(true);
        ui->btnFrameClear->setEnabled(true);
        ui->btnFrameDelete->setEnabled(true);
        ui->btnFrameInsertBefore->setEnabled(true);
        ui->btnFrameInsertAfter->setEnabled(true);

        ui->statusBar->showMessage("Edit Mode");
    }
}

void MainWindow::onTimeLineFrameSelected(int index)
{
    if (!isPlayMode)
    {
        selectFrame(index);
    }
}

void MainWindow::selectFrame(int index)
{
    widgetTimeLine->setFrameIndex(index);
    LedFrame ledFrame = modelMovie.getFrame(index);
    widgetLeds->setLedFrame(ledFrame);
}

void MainWindow::selectNextFrame()
{
    int frameIndex = widgetTimeLine->getFrameIndex();
    const int frameCount = widgetTimeLine->getFrameCount();

    if (frameIndex >= (frameCount-1))
        frameIndex = 0;
    else
        ++frameIndex;

    selectFrame(frameIndex);
}

int MainWindow::getCurrentDelay() const
{
   const double SCALE_FACTOR = 10.0;

   int res = 0;

   if (widgetTimeLine->getFrameCount() > 0)
   {
       const int frameIndex = widgetTimeLine->getFrameIndex();
       LedFrame ledFrame = modelMovie.getFrame(frameIndex);
       res = static_cast<uint>(ledFrame.getDelay());
       res = int(((double)res * SCALE_FACTOR) + 0.5);
   }

   return res;
}

void MainWindow::goTimer()
{
    const int delay = getCurrentDelay();
    QTimer::singleShot(delay, this, SLOT(onTimerEvent()));
}

void MainWindow::onLedFrameChanged()
{
    const int frameIndex = widgetTimeLine->getFrameIndex();
    LedFrame ledFrame = widgetLeds->getLedFrame();
    modelMovie.setFrame(frameIndex, ledFrame);
    selectFrame(frameIndex);
}

void MainWindow::onTimerEvent()
{
    if (isPlayMode)
    {
        selectNextFrame();
        goTimer();
    }
}
