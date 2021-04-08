#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QCamera* _camera;
    QCameraViewfinder* _viewfinder;
    QCameraImageCapture* _imageCapture;
    QCameraImageProcessing *_imageProcessing;
private slots:
    void sltCaptureImage();
    void sltDisplayImage(int, QImage);
    void sltSaveImage();

};
#endif // MAINWINDOW_H
