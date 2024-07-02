#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir("Images");
    QStringList filenames = dir.entryList();
    qreal w = ui->image->width(), h = ui->image->height();

    for(auto& filename: filenames){
        if(filename.endsWith(".png")){
            QPixmap image(dir.absoluteFilePath(filename));
            qDebug() << dir.absoluteFilePath(filename);
            images.append(image.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

    //ui->image->setPixmap(image.scaledToWidth(w, Qt::SmoothTransformation));
    if(images.size() > 0) ui->image->setPixmap(images[0]);
    else ui->statusbar->showMessage("Images not found!");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_next_clicked()
{
    if(index + 1 < images.size()) index++;
    ui->image->setPixmap(images[index]);
}


void MainWindow::on_prev_clicked()
{
    if(index - 1 >= 0) index--;
    ui->image->setPixmap(images[index]);
}

