#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainwidget.h>
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    unsigned int fps_counter;
    MainWidget *widget;
    QLabel *status_label;

private slots:
    void update_fps();
};

#endif // MAINWINDOW_H
