#include "chart_and_random_array.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chart_and_random_array w;
    w.show();
    w.gen_chart();
    w.set_style_sheet();
    return a.exec();
}
