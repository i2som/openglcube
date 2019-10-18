#ifndef MAIN_H
#define MAIN_H
#include <QTimer>
#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
/*
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update_fps();
*/
private:
    unsigned int fps_counter;
    QLabel *status_label;
};

#endif // MAIN_H
