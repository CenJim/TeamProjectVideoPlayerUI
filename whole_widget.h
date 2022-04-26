#ifndef WHOLE_WIDGET_H
#define WHOLE_WIDGET_H

#include <QWidget>
#include "initial_window.h"
#include "full_screen.h"
#include <QFileDialog>
extern ThePlayer *player;

class whole_widget:public QWidget
{
    Q_OBJECT
public:
    whole_widget();
    QVideoWidget *videoWidget = new QVideoWidget;
    void makeConnections();

private:
    initial_window *initialWidget = new initial_window();
    full_screen *fullscreenWidget = new full_screen();

public slots:
    void initialShow();
    void fullwindowShow();
    void setPlayer();
    void openFile();
};

#endif // WHOLE_WIDGET_H
