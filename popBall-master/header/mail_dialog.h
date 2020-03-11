#ifndef MAIL_DIALOG_H
#define MAIL_DIALOG_H

#include <QDialog>

namespace Ui {
class MailDialog;
}

class MailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MailDialog(QWidget *parent = nullptr);
    ~MailDialog();

private:
    Ui::MailDialog *ui;
};

#endif // MAIL_DIALOG_H
