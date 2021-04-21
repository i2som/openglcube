#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widget = new MainWidget(ui->label_cube);
    widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

//    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
//    layout->addWidget(widget);
//    ui->centralwidget->setLayout(layout);

    QString str;
    str.sprintf("fps: %d", widget->m_frameCount);
    ui->label_fps->setText(str);
//    status_label = new QLabel(str, this);
//    ui->statusbar->addPermanentWidget(status_label);

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_fps()));
    widget->m_frameCount = 0;
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    qDebug() << endl << "Window Resize:" << this->size();

    // 屏幕长宽
    QList<QScreen*> scr = QGuiApplication::screens();
    QRect rect = scr.at(0)->geometry();
    quint32 desktop_wid = rect.width();
    quint32 desktop_hei = rect.height();

    // 根据不同屏幕分辨率, 调节字体大小
    QString style_str;
    if (desktop_wid >= 1280 && desktop_hei >= 720) {
        qDebug() << "1280*720";
        style_str = QString("font: 20pt \"WenQuanYi Micro Hei Mono\";");
    } else if (desktop_wid >= 800 && desktop_hei >= 600) {
        qDebug() << "800*600";
        style_str = QString("font: 10pt \"WenQuanYi Micro Hei Mono\";");
    }

    ui->pushButton_exit->setStyleSheet(style_str);
    ui->label_fps->setStyleSheet(style_str);

    quint32 min = qMin(ui->frame->size().width(), ui->frame->size().height()) * 0.8;
    qDebug() << "Frame:" << ui->frame->size() << min;
    ui->label_cube->setGeometry((ui->frame->size().width()-min)/2, (ui->frame->size().height()-min)/2, min, min);
    widget->resize(QSize(min, min));
}

void MainWindow::update_fps()
{
    QString str;
    str.sprintf("fps: %d", widget->m_frameCount);
    ui->label_fps->setText(str);

    widget->m_frameCount = 0;
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}
