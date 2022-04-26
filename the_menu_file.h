#ifndef THE_MENU_FILE_H
#define THE_MENU_FILE_H

#include <QMenu>

class FileMenu : public QMenu {
    Q_OBJECT
private:
    QAction* openfileAction;
    QAction* openmediaAction;
    QAction* openfolderAction;
    QAction* closefileAction;
    QAction* closemediaAction;
    QAction* closeallAction;
    QAction* saveAction;
    QAction* saveasAction;
    QAction* exportAction;
    QAction* shareAction;
    QAction* exitAction;
    QAction* quitAction;
public:
    FileMenu(const QString &title);
    void makeConnections();
signals:
    void openFile_triggered();
};

#endif // THE_MENU_FILE_H
