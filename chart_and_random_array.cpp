#include "chart_and_random_array.h"
#include "ui_chart_and_random_array.h"

void Chart_and_random_array::playback_step()
{
    time_elapsed += 10;

    for(int i = 0; i < x.size(); i++)
    {
        if(time_elapsed >= x[i])
        {
            x2.push_back(x[i]);
            y2.push_back(y[i]);
            x.pop_front();
            y.pop_front();
            i = 0;
        }
    }

    ui->widget->graph(0)->setData(x2, y2);

    if(x.size() == 0)
    {
        playback_timer->stop();
    }

    ui->widget->replot();
}

void Chart_and_random_array::gen_chart()
{
    connect(playback_timer, SIGNAL(timeout()), this, SLOT(playback_step()));

    x.reserve(100);
    y.reserve(100);
    x2.reserve(100);
    y2.reserve(100);

    srand(time(nullptr));

    ui->widget->addGraph();

    ui->widget->xAxis->setRange(0, 500);
    ui->widget->yAxis->setRange(0, 500);

    ui->widget->graph(0)->setPen(QColor(30, 144, 255, 255));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 6));

    for(int i = 0; i < 50; i++)
    {
        x.push_back(10 * i);
        y.push_back(10 + rand() % 100 + i * 8);
    }
}

void Chart_and_random_array::start_chart()
{
    if(!playback_timer->isActive())
    {
        playback_timer->start(1000); // Отрисовка раз в секунду
    }
}

void Chart_and_random_array::pause_chart()
{
    if(playback_timer->isActive())
    {
        playback_timer->stop();
    }
}

void Chart_and_random_array::stop_and_clear_chart()
{
    QMessageBox msg_box;
    msg_box.setText("Вы действительно хотите выйти?");
    msg_box.setWindowTitle("Выход");
    msg_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg_box.setIcon(QMessageBox::Warning);
    msg_box.setDefaultButton(QMessageBox::No);
    if(msg_box.exec() == QMessageBox::No)
    {
        return;
    }
    else
    {
        if(playback_timer->isActive())
        {
            playback_timer->stop();
        }

        ui->widget->clearGraphs();
        ui->widget->replot();
        QThread::sleep(1);
        this->close();
        exit(0);
    }
}

void Chart_and_random_array::set_style_sheet()
{
    unique_ptr<Style_sheet_preset> style_sheet(new Style_sheet_preset);

    this->setStyleSheet(style_sheet->window_gray());

    ui->groupBox->setStyleSheet(style_sheet->groupbox_white());
    ui->groupBox_2->setStyleSheet(style_sheet->groupbox_blue());

    ui->label->setStyleSheet(style_sheet->label_white());

    ui->pushButton->setStyleSheet(style_sheet->buttom_gray_blue());
    ui->pushButton_2->setStyleSheet(style_sheet->buttom_gray_blue());
    ui->pushButton_3->setStyleSheet(style_sheet->buttom_gray_blue());

    ui->pushButton->setToolTip("Старт - запуск генерируемого массива");
    ui->pushButton_2->setToolTip("Пауза - фиксирование значений на графике");
    ui->pushButton_3->setToolTip("Стоп - очистка графика и закрытие окна");
}

Chart_and_random_array::Chart_and_random_array(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chart_and_random_array)
{
    ui->setupUi(this);
}

Chart_and_random_array::~Chart_and_random_array()
{
    delete playback_timer;
    delete ui;
}

void Chart_and_random_array::on_pushButton_clicked()
{
    start_chart();
}

void Chart_and_random_array::on_pushButton_2_clicked()
{
    pause_chart();
}

void Chart_and_random_array::on_pushButton_3_clicked()
{
    stop_and_clear_chart();
}
