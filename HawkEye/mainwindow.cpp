#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList name;
    foreach(const QCameraInfo &cameraInfo, QCameraInfo::availableCameras())
    {
        name << cameraInfo.deviceName();
    }

    _camera = new QCamera(this);
    _viewfinder=new QCameraViewfinder(this);
    _imageCapture=new QCameraImageCapture(_camera);

    ui->ImageView->addWidget(_viewfinder);
    ui->ImageCapture->setScaledContents(true);

    _camera->setViewfinder(_viewfinder);
    _camera->setCaptureMode(QCamera::CaptureStillImage);
    _camera->start();

    connect(_imageCapture, &QCameraImageCapture::imageCaptured, this, &MainWindow::sltDisplayImage);
    connect(ui->pushButton_capture, &QPushButton::clicked, this, &MainWindow::sltCaptureImage);
    connect(ui->pushButton_save, &QPushButton::clicked, this, &MainWindow::sltSaveImage);
    connect(ui->pushButton_quit, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sltCaptureImage()
{
    ui->statusbar->showMessage(tr("capturing..."), 1000);
    _imageCapture->capture();
}

void MainWindow::sltDisplayImage(int, QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
    ui->statusbar->showMessage(tr("capture OK!"), 5000);
}

void MainWindow::sltSaveImage()
{

}

