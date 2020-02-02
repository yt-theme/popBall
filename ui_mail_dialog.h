/********************************************************************************
** Form generated from reading UI file 'mail_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIL_DIALOG_H
#define UI_MAIL_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MailDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *disconnectButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *configButton;
    QTableView *tableView;

    void setupUi(QDialog *MailDialog)
    {
        if (MailDialog->objectName().isEmpty())
            MailDialog->setObjectName(QString::fromUtf8("MailDialog"));
        MailDialog->resize(480, 420);
        gridLayout = new QGridLayout(MailDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        disconnectButton = new QPushButton(MailDialog);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

        gridLayout->addWidget(disconnectButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        configButton = new QPushButton(MailDialog);
        configButton->setObjectName(QString::fromUtf8("configButton"));

        gridLayout->addWidget(configButton, 0, 2, 1, 1);

        tableView = new QTableView(MailDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 3);


        retranslateUi(MailDialog);

        QMetaObject::connectSlotsByName(MailDialog);
    } // setupUi

    void retranslateUi(QDialog *MailDialog)
    {
        MailDialog->setWindowTitle(QCoreApplication::translate("MailDialog", "Dialog", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MailDialog", "disconnect", nullptr));
        configButton->setText(QCoreApplication::translate("MailDialog", "configure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MailDialog: public Ui_MailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIL_DIALOG_H
