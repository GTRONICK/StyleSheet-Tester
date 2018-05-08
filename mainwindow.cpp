#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gsThemePath = "";
    ui->setupUi(this);
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_valueChanged(int value)
{
    this->ui->DialSliderH->setValue(value);
    this->ui->DialHScrollBar->setValue(value);
    this->ui->DialSliderV->setValue(value);
    this->ui->DialVScrollBar->setValue(value);
}

void MainWindow::on_actionDefine_theme_path_triggered()
{
    gsThemePath = QFileDialog::getOpenFileName(this, tr("Open Theme file"), "", tr("Qt StyleSheet Files (*.qss);;Text files (*.txt);;All files (*.*)"));
    loadThemeFile();
}

bool MainWindow::loadThemeFile()
{
    QFile *lobConfigFile = new QFile(gsThemePath);
    if(!lobConfigFile->open(QFile::ReadOnly)){

        return false;
    }

    QFile style(gsThemePath);

    if(style.exists() && style.open(QFile::ReadOnly)) {
        QString styleContents = QLatin1String(style.readAll());
        style.close();
        this->setStyleSheet(styleContents);
    }

    lobConfigFile->close();

    return true;
}

void MainWindow::on_actionReload_theme_triggered()
{
    this->loadThemeFile();
}

void MainWindow::on_ProgessBarControl_valueChanged(int value)
{
    ui->progressBar->setValue(value);
    ui->lcdNumber->display(value);
}
