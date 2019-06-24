#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);
        MainWindow::makePlot();
    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::makePlot() {
        qDebug()<<QDir::currentPath()<<"\n";
        QVector<double> x3(1), y3(1), x4(1), y4(1), y2(2);
        std::string filename;
        int number;
        filename = "./file.txt";
        QFile file(filename.c_str());
        file.open(QFile::ReadOnly);
        int i = 0;

        if (!file.exists())
            qDebug()<<"File doesn't exist\n";

        QTextStream in (&file);
        if (in.atEnd())
            qDebug()<<"At end";
        else
            qDebug()<<"Not end";
    
        while(!in.atEnd()){
            QString s = in.readLine();
            y2[i] = s.toInt();
            i++;
        }
    
        y3[0]=y2[0];
        y4[0]=y2[1];
    
        for (int i = 1; i <= x3.size(); ++i) {
            x3[i-1] = i;
            x4[i-1] = i+1;
        }

        // create and configure plottables:


        QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
        bars1->setWidth(0.5);
        bars1->setData(x3, y3);
        QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
        bars2->setWidth(0.5);
        bars2->setData(x4, y4);
        bars1->setBrush(QColor(0, 255, 0, 160));
        bars2->setBrush(QColor(255,0,0,160));

        // move bars above graphs and grid below bars:
        QVector<double> ticks;
        QVector<QString> labels;
        ticks << 1 << 2;
        labels << "Cache Hit" << "Cache Miss";
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(ticks, labels);
        ui->customPlot->xAxis->setTicker(textTicker);
        ui->customPlot->xAxis->setSubTicks(false);
        ui->customPlot->xAxis->setTickLength(0,1);
        // set some pens, brushes and backgrounds:
        ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
        ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
        ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
        ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
        ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->customPlot->xAxis->setTickLabelColor(Qt::white);
        ui->customPlot->yAxis->setTickLabelColor(Qt::white);
        ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
        ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
        ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
        ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
        ui->customPlot->xAxis->grid()->setSubGridVisible(true);
        ui->customPlot->yAxis->grid()->setSubGridVisible(true);
        ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
        ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
        QLinearGradient plotGradient;
        plotGradient.setStart(0, 0);
        plotGradient.setFinalStop(0, 350);
        plotGradient.setColorAt(0, QColor(80, 80, 80));
        plotGradient.setColorAt(1, QColor(50, 50, 50));
        ui->customPlot->setBackground(plotGradient);
        QLinearGradient axisRectGradient;
        axisRectGradient.setStart(0, 0);
        axisRectGradient.setFinalStop(0, 350);
        axisRectGradient.setColorAt(0, QColor(80, 80, 80));
        axisRectGradient.setColorAt(1, QColor(30, 30, 30));
        ui->customPlot->axisRect()->setBackground(axisRectGradient);
        ui->customPlot->rescaleAxes();
        ui->customPlot->yAxis->setRange(0, 150);
        ui->customPlot->xAxis->setRange(0, 3);
    }
