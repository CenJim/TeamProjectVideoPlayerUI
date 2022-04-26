// ADD by Victor Zhang
// 2021/21/2

#include "initial_window.h"

initial_window::initial_window()
{
    setUI();
    initialSignal();
    setWindowTitle("Submit Interface");
}

void initial_window::setUI()
{
    QLabel *space = new QLabel("");
    signTitle = new QLabel("  Login In");
    QFont font = signTitle->font();
    font.setPointSize(20);
    signTitle->setFont(font);

    username = new QLabel("User Name:");
    nameField = new QLineEdit;
    QHBoxLayout *input_name = new QHBoxLayout;
    input_name->addWidget(username);
    input_name->addWidget(nameField);

    password = new QLabel("Password: ");
    passwordField = new QLineEdit;
    QHBoxLayout *input_password = new QHBoxLayout;
    input_password->addWidget(password);
    input_password->addWidget(passwordField);

    submitButton = new QPushButton("submit");
    closeButton = new QPushButton("close");
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(submitButton);
    buttonLayout->addWidget(space);
    buttonLayout->addWidget(space);
    buttonLayout->addWidget(space);
    buttonLayout->addWidget(closeButton);

    QVBoxLayout *signinLayout = new QVBoxLayout;
    signinLayout->addWidget(signTitle);
    signinLayout->addWidget(space);
    signinLayout->addLayout(input_name);
    signinLayout->addWidget(space);
    signinLayout->addLayout(input_password);
    signinLayout->addWidget(space);
    signinLayout->addLayout(buttonLayout);
    signinLayout->addWidget(space);
    setLayout(signinLayout);
}

void initial_window::initialSignal()
{
    connect(submitButton,SIGNAL(clicked()),this,SLOT(on_Login()));
}

void initial_window::on_Login()
{
    static int cout = 0;
    QString user = nameField->text();
    QString pass = passwordField->text();
    QString p="";
    int lenth = pass.count();
    for(int i=0; i < lenth; i++)p.append("*");
    passwordField->setText(p);

    if(user == "Leedsuser" && pass == "123456") {
        signTitle->setStyleSheet("color:green;");
        p="  Login Successful";
        connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    }
    else {
        signTitle->setStyleSheet("color:red;");
        p="  Login Failed";
        cout++;
    }

    if(cout >= 4) {
        signTitle->setStyleSheet("color:red;");
        p = "Too many failed operations!  Login is prohibited";
        disconnect(submitButton,SIGNAL(clicked),this,SLOT(on_Login()));
    }
    int len = user.count();
    if(len == 0 || lenth == 0) {
        signTitle->setStyleSheet("color:red;");
        p="  Nothing Entered";cout--;
    }
    signTitle->setText(p);
}
