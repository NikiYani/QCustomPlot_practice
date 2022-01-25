#ifndef CHART_AND_RANDOM_ARRAY_H
#define CHART_AND_RANDOM_ARRAY_H

#include <style_sheet_preset.h>
#include <qcustomplot.h>
#include <QMainWindow>
#include <QShortcut>
#include <QThread>
#include <memory>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Chart_and_random_array; }
QT_END_NAMESPACE

using namespace std;

class Chart_and_random_array : public QMainWindow
{
    Q_OBJECT

public:
    Chart_and_random_array(QWidget *parent = nullptr);
    ~Chart_and_random_array();

    void gen_chart();
    void start_chart();
    void pause_chart();
    void stop_and_clear_chart();
    void set_style_sheet();

private slots:
    void playback_step();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    QTimer *playback_timer = new QTimer(this);
    Ui::Chart_and_random_array *ui;
    QVector<double> x, x2, y, y2;
    int time_elapsed = 0;
};
#endif // CHART_AND_RANDOM_ARRAY_H
