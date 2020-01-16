#include "header/mail_dialog.h"
#include "ui_mail_dialog.h"

MailDialog::MailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MailDialog)
{
    ui->setupUi(this);
}

MailDialog::~MailDialog()
{
    delete ui;
}
