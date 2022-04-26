#include "whole_widget.h"

whole_widget::whole_widget()
{
    makeConnections();
}

void whole_widget::initialShow() {
    initialWidget->resize(400, 200);
    initialWidget->show();
}

void whole_widget::fullwindowShow() {

    fullscreenWidget->setUI();
    fullscreenWidget->resize(800, 680);
    fullscreenWidget->show();
}

void whole_widget::setPlayer(){
    player->setVideoOutput(videoWidget);
}

void whole_widget::makeConnections(){
    connect(fullscreenWidget,SIGNAL(quitPushed()),this,SLOT(setPlayer()));
}

void whole_widget::openFile(){
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Config"), "/home", tr("all (*.png *.jpg *.jpeg *.wmv *.MOV *.mp4)"));



    if (!fileName.isNull())

    {

    //fileName即是选择的文件名

    }

    else
    {
    //点是的取消
    }
}
