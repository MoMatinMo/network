#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool testInternetConnection();
    void testConnection();

    QLabel *resultLabel = new QLabel(this);
    QPushButton *testButton = new QPushButton(this);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
