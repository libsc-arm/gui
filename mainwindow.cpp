#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Vulnerability Testing Tool");
    QPixmap bkgnd("assets/background.png");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::on_pushButton_clicked() {
        ui->stackedWidget->setCurrentIndex(2);
    }

    void MainWindow::on_pushButton_2_clicked() {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_pushButton_3_clicked() {
        std::system("./scripts/init.sh");
        ui->stackedWidget->setCurrentIndex(3);
    }

    void MainWindow::on_pushButton_4_clicked() {
        ui->stackedWidget->setCurrentIndex(2); 
    }

    void MainWindow::on_pushButton_5_clicked() {
        std::system("./scripts/build.sh");
        ui->stackedWidget->setCurrentIndex(4);
    }

    void MainWindow::on_pushButton_6_clicked() {
        std::system("./scripts/run.sh");
        ui->stackedWidget->setCurrentIndex(5);
    }

    void MainWindow::on_pushButton_8_clicked() {
        ui->label_2->setText("Click NEXT");
    }

    void MainWindow::on_commandLinkButton_clicked() {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_pushButton_7_clicked() {
        std::system("./graph/cacheplot");
        ui->stackedWidget->setCurrentIndex(6);
    }
