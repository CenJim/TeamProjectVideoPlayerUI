#ifndef INITIAL_WINDOW_H
#define INITIAL_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>

class initial_window : public QWidget
{
    Q_OBJECT
public:
    QPushButton* submitButton;
    QPushButton* closeButton;
    QLabel *username;
    QLabel *password;
    QLabel *signTitle;
    QLineEdit *nameField;
    QLineEdit *passwordField;

private slots:
    void setUI();
    void initialSignal();
    void on_Login();

public:
    initial_window();
};

#endif // INITIAL_WINDOW_H
