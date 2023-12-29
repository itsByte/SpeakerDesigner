#include "mainwindow.h"
#include "ui/ui_mainwindow.h"
#include "response.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto resp = new Response;
    auto file = new QFile("/home/itsbyte/Downloads/E150HE-44_data/FRD/E150HE-44@0.frd");
    resp->ImportFRD(*file);
    ui->tab->Populate(resp->getAmplitude());
}

MainWindow::~MainWindow()
{
    delete ui;
}
