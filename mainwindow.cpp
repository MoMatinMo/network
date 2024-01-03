#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QCoreApplication>
#include <QProcess>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Internet Connection Test"); // Set window title

    // Set window size and position
    setFixedSize(400, 200);
    move(500, 300);


    resultLabel = new QLabel(this);
    testButton = new QPushButton(this);

    // Add a label to display the result
    resultLabel->setGeometry(150, 100, 100, 30);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setText("Testing...");

    // Add a button to initiate the test

    testButton->setGeometry(150, 150, 100, 30);
    testButton->setText("Test Connection");

    // Connect the button's clicked signal to a slot
    connect(testButton, &QPushButton::clicked, this, &MainWindow::testConnection);
}


bool MainWindow::testInternetConnection()
{
    QProcess process;
    process.start("ping", QStringList() << "-c" << "1" << "www.google.com");
    process.waitForFinished();

    if (process.exitCode() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::testConnection()
{
    bool isConnected = testInternetConnection();

    if (isConnected)
    {
        resultLabel->setText("Connected");
    }
    else
    {
        resultLabel->setText("Not Connected");
    }
}




MainWindow::~MainWindow()
{
    delete ui;
}

