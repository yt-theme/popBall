/********************************************************************************
** Form generated from reading UI file 'configure_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_DIALOG_H
#define UI_CONFIGURE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConfigureDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *cpu_line_color;
    QLabel *label_7;
    QPushButton *select_color_swap;
    QLabel *label_9;
    QLineEdit *main_color;
    QLineEdit *system_monitor_path;
    QLabel *label_12;
    QLabel *label_2;
    QLineEdit *outer_border_color;
    QLabel *label_11;
    QLineEdit *main_opacity;
    QPushButton *select_color_cpu_line;
    QLineEdit *swap_chart_color;
    QLabel *label_8;
    QPushButton *select_color_cpu_usage;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *label_3;
    QLabel *label_14;
    QLabel *label_5;
    QPushButton *restore_configure;
    QLineEdit *mem_chart_color;
    QLineEdit *cpu_usage_color;
    QLabel *label_4;
    QGroupBox *groupBox;
    QRadioButton *radioButton_net;
    QRadioButton *radioButton_cpu;
    QGridLayout *gridLayout_2;
    QLabel *tips;
    QPushButton *select_color_mem;
    QLabel *label_13;
    QLineEdit *refresh_interval;
    QLineEdit *labelFont_size;
    QPushButton *select_color_outer_border;
    QLabel *label;
    QCheckBox *showCpu_checkbox;
    QPushButton *select_color_main;

    void setupUi(QDialog *ConfigureDialog)
    {
        if (ConfigureDialog->objectName().isEmpty())
            ConfigureDialog->setObjectName(QString::fromUtf8("ConfigureDialog"));
        ConfigureDialog->resize(420, 623);
        gridLayout = new QGridLayout(ConfigureDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cpu_line_color = new QLineEdit(ConfigureDialog);
        cpu_line_color->setObjectName(QString::fromUtf8("cpu_line_color"));
        cpu_line_color->setEnabled(true);
        cpu_line_color->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(cpu_line_color, 8, 1, 1, 1);

        label_7 = new QLabel(ConfigureDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        select_color_swap = new QPushButton(ConfigureDialog);
        select_color_swap->setObjectName(QString::fromUtf8("select_color_swap"));

        gridLayout->addWidget(select_color_swap, 7, 2, 1, 1);

        label_9 = new QLabel(ConfigureDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        main_color = new QLineEdit(ConfigureDialog);
        main_color->setObjectName(QString::fromUtf8("main_color"));
        main_color->setEnabled(true);
        main_color->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(main_color, 4, 1, 1, 1);

        system_monitor_path = new QLineEdit(ConfigureDialog);
        system_monitor_path->setObjectName(QString::fromUtf8("system_monitor_path"));
        system_monitor_path->setMinimumSize(QSize(163, 0));
        system_monitor_path->setSizeIncrement(QSize(0, 0));
        system_monitor_path->setBaseSize(QSize(0, 0));
        system_monitor_path->setMaxLength(32765);

        gridLayout->addWidget(system_monitor_path, 11, 1, 1, 1);

        label_12 = new QLabel(ConfigureDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 9, 0, 1, 1);

        label_2 = new QLabel(ConfigureDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        outer_border_color = new QLineEdit(ConfigureDialog);
        outer_border_color->setObjectName(QString::fromUtf8("outer_border_color"));
        outer_border_color->setEnabled(true);
        outer_border_color->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(outer_border_color, 5, 1, 1, 1);

        label_11 = new QLabel(ConfigureDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        main_opacity = new QLineEdit(ConfigureDialog);
        main_opacity->setObjectName(QString::fromUtf8("main_opacity"));
        main_opacity->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(main_opacity, 3, 1, 1, 1);

        select_color_cpu_line = new QPushButton(ConfigureDialog);
        select_color_cpu_line->setObjectName(QString::fromUtf8("select_color_cpu_line"));

        gridLayout->addWidget(select_color_cpu_line, 8, 2, 1, 1);

        swap_chart_color = new QLineEdit(ConfigureDialog);
        swap_chart_color->setObjectName(QString::fromUtf8("swap_chart_color"));
        swap_chart_color->setEnabled(true);
        swap_chart_color->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(swap_chart_color, 7, 1, 1, 1);

        label_8 = new QLabel(ConfigureDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        select_color_cpu_usage = new QPushButton(ConfigureDialog);
        select_color_cpu_usage->setObjectName(QString::fromUtf8("select_color_cpu_usage"));

        gridLayout->addWidget(select_color_cpu_usage, 9, 2, 1, 1);

        label_6 = new QLabel(ConfigureDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 14, 1, 1, 1);

        label_10 = new QLabel(ConfigureDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        label_15 = new QLabel(ConfigureDialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 11, 0, 1, 1);

        label_3 = new QLabel(ConfigureDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_14 = new QLabel(ConfigureDialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 10, 0, 1, 1);

        label_5 = new QLabel(ConfigureDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        restore_configure = new QPushButton(ConfigureDialog);
        restore_configure->setObjectName(QString::fromUtf8("restore_configure"));

        gridLayout->addWidget(restore_configure, 12, 1, 1, 1);

        mem_chart_color = new QLineEdit(ConfigureDialog);
        mem_chart_color->setObjectName(QString::fromUtf8("mem_chart_color"));
        mem_chart_color->setEnabled(true);
        mem_chart_color->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(mem_chart_color, 6, 1, 1, 1);

        cpu_usage_color = new QLineEdit(ConfigureDialog);
        cpu_usage_color->setObjectName(QString::fromUtf8("cpu_usage_color"));
        cpu_usage_color->setEnabled(true);
        cpu_usage_color->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(cpu_usage_color, 9, 1, 1, 1);

        label_4 = new QLabel(ConfigureDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        groupBox = new QGroupBox(ConfigureDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 40));
        radioButton_net = new QRadioButton(groupBox);
        radioButton_net->setObjectName(QString::fromUtf8("radioButton_net"));
        radioButton_net->setGeometry(QRect(10, 10, 61, 22));
        radioButton_cpu = new QRadioButton(groupBox);
        radioButton_cpu->setObjectName(QString::fromUtf8("radioButton_cpu"));
        radioButton_cpu->setGeometry(QRect(90, 10, 61, 22));

        gridLayout->addWidget(groupBox, 10, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tips = new QLabel(ConfigureDialog);
        tips->setObjectName(QString::fromUtf8("tips"));
        QFont font;
        font.setPointSize(8);
        tips->setFont(font);

        gridLayout_2->addWidget(tips, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 13, 0, 1, 3);

        select_color_mem = new QPushButton(ConfigureDialog);
        select_color_mem->setObjectName(QString::fromUtf8("select_color_mem"));

        gridLayout->addWidget(select_color_mem, 6, 2, 1, 1);

        label_13 = new QLabel(ConfigureDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        refresh_interval = new QLineEdit(ConfigureDialog);
        refresh_interval->setObjectName(QString::fromUtf8("refresh_interval"));
        refresh_interval->setMinimumSize(QSize(163, 0));
        refresh_interval->setSizeIncrement(QSize(0, 0));
        refresh_interval->setBaseSize(QSize(0, 0));
        refresh_interval->setMaxLength(32765);

        gridLayout->addWidget(refresh_interval, 0, 1, 1, 1);

        labelFont_size = new QLineEdit(ConfigureDialog);
        labelFont_size->setObjectName(QString::fromUtf8("labelFont_size"));
        labelFont_size->setMinimumSize(QSize(163, 0));

        gridLayout->addWidget(labelFont_size, 2, 1, 1, 1);

        select_color_outer_border = new QPushButton(ConfigureDialog);
        select_color_outer_border->setObjectName(QString::fromUtf8("select_color_outer_border"));

        gridLayout->addWidget(select_color_outer_border, 5, 2, 1, 1);

        label = new QLabel(ConfigureDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        showCpu_checkbox = new QCheckBox(ConfigureDialog);
        showCpu_checkbox->setObjectName(QString::fromUtf8("showCpu_checkbox"));

        gridLayout->addWidget(showCpu_checkbox, 1, 1, 1, 1);

        select_color_main = new QPushButton(ConfigureDialog);
        select_color_main->setObjectName(QString::fromUtf8("select_color_main"));

        gridLayout->addWidget(select_color_main, 4, 2, 1, 1);


        retranslateUi(ConfigureDialog);

        QMetaObject::connectSlotsByName(ConfigureDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigureDialog)
    {
        ConfigureDialog->setWindowTitle(QCoreApplication::translate("ConfigureDialog", "Dialog", nullptr));
        cpu_line_color->setText(QString());
        label_7->setText(QCoreApplication::translate("ConfigureDialog", "Main Color", nullptr));
        select_color_swap->setText(QCoreApplication::translate("ConfigureDialog", "select", nullptr));
        label_9->setText(QCoreApplication::translate("ConfigureDialog", "Mem Chart Color", nullptr));
        label_12->setText(QCoreApplication::translate("ConfigureDialog", "Cpu Usage Color", nullptr));
        label_2->setText(QCoreApplication::translate("ConfigureDialog", "ms", nullptr));
        outer_border_color->setText(QString());
        label_11->setText(QCoreApplication::translate("ConfigureDialog", "Cpu Line Color", nullptr));
        select_color_cpu_line->setText(QCoreApplication::translate("ConfigureDialog", "select", nullptr));
        swap_chart_color->setText(QString());
        label_8->setText(QCoreApplication::translate("ConfigureDialog", "Outer Border Color", nullptr));
        select_color_cpu_usage->setText(QCoreApplication::translate("ConfigureDialog", "select", nullptr));
        label_6->setText(QCoreApplication::translate("ConfigureDialog", "Main Opacity", nullptr));
        label_10->setText(QCoreApplication::translate("ConfigureDialog", "Swap Chart Color", nullptr));
        label_15->setText(QCoreApplication::translate("ConfigureDialog", "System Monitor", nullptr));
        label_3->setText(QCoreApplication::translate("ConfigureDialog", "Show CPU label", nullptr));
        label_14->setText(QCoreApplication::translate("ConfigureDialog", "Show Net Or Cpu", nullptr));
        label_5->setText(QCoreApplication::translate("ConfigureDialog", "px", nullptr));
        restore_configure->setText(QCoreApplication::translate("ConfigureDialog", "restore", nullptr));
        mem_chart_color->setText(QString());
        cpu_usage_color->setText(QString());
        label_4->setText(QCoreApplication::translate("ConfigureDialog", "Label Font Size", nullptr));
        groupBox->setTitle(QString());
        radioButton_net->setText(QCoreApplication::translate("ConfigureDialog", "net", nullptr));
        radioButton_cpu->setText(QCoreApplication::translate("ConfigureDialog", "cpu", nullptr));
        tips->setText(QCoreApplication::translate("ConfigureDialog", "tips:", nullptr));
        select_color_mem->setText(QCoreApplication::translate("ConfigureDialog", "select", nullptr));
        label_13->setText(QCoreApplication::translate("ConfigureDialog", "Restore Configure", nullptr));
        select_color_outer_border->setText(QCoreApplication::translate("ConfigureDialog", "select", nullptr));
        label->setText(QCoreApplication::translate("ConfigureDialog", "Refresh Interval", nullptr));
        showCpu_checkbox->setText(QCoreApplication::translate("ConfigureDialog", "show", nullptr));
        select_color_main->setText(QCoreApplication::translate("ConfigureDialog", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigureDialog: public Ui_ConfigureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_DIALOG_H
