#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *exit_action =  menuBar()->addAction("Exit");
    connect(exit_action, SIGNAL(triggered(bool)), this, SLOT(close()));

    widget = new MainWidget(this);
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    layout->addWidget(widget);
    ui->centralwidget->setLayout(layout);

    QString str;
    str.sprintf("fps: %d", widget->m_frameCount);
    status_label = new QLabel(str, this);
    ui->statusbar->addPermanentWidget(status_label);

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_fps()));
    widget->m_frameCount = 0;
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_fps()
{
    QString str;
    str.sprintf("fps: %d", widget->m_frameCount);
    status_label->setText(str);

    widget->m_frameCount = 0;
}
