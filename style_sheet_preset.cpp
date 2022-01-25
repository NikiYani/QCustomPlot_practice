#include "style_sheet_preset.h"

Style_sheet_preset::Style_sheet_preset()
{

}

Style_sheet_preset::~Style_sheet_preset()
{

}

QString Style_sheet_preset::buttom_gray_blue(){
    return "QPushButton {background-color : #dbdce1;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-color: #ffffff;"
    "color: #000000;"
    "font: bold 14px;"
    "text-align: center;}"

    "QPushButton:hover {background-color : #4c7bd9;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-color: #ffffff;"
    "color: #ffffff;"
    "font: bold 14px;"
    "text-align: center;}"

    "QPushButton:pressed { background-color : #2f477b;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-color: #ffffff;"
    "color: #ffffff;"
    "font: bold 14px;"
    "text-align: center;}"

    "QPushButton:!enabled { background-color : #f5f5f5;"
    "border-style: outset;"
    "border-width: 2px;"
    "border-color: #ffffff;"
    "color: #dbdce1;"
    "font: bold 14px;"
    "text-align: center;}";
}

QString Style_sheet_preset::window_gray(){
    return "QDialog {background-color : #dbdce1;}";
}

QString Style_sheet_preset::label_white(){
    return "QLabel {color: #ffffff;"
           "text-align: right;}";
}

QString Style_sheet_preset::groupbox_white(){
    return "QGroupBox {background-color: #ffffff;"
           "color: #2f477b;"
           "font: bold 14;"
           "border-style: outset;"
           "border-width: 2px;"
           "border-color: #ECF0F1;}";
}

QString Style_sheet_preset::groupbox_blue(){
    return "QGroupBox {background-color: #4462a2;"
           "color: #ffffff;"
           "font: bold 14;"
           "border-style: outset;"
           "border-width: 2px;"
           "border-color: #ECF0F1;}";
}
