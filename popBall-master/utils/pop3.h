#ifndef UTILS_POP3_H
#define UTILS_POP3_H

#include <QTcpSocket>
#include <QString>

class Pop3 {

public:
    Pop3();
    ~Pop3();

    bool connect_server();  // connect step
    bool login();           // login state
    bool logout();          // clear login info

private:
    QString server = "";    // login info
    QString port   = "25";
    QString username;
    QString password;
};

#endif // UTILS_POP3_H
