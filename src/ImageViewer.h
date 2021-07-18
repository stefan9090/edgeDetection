//
// Created by stefan on 7/16/21.
//

#ifndef EDGEDETECTION_IMAGEVIEWER_H
#define EDGEDETECTION_IMAGEVIEWER_H

#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QTextEdit>

class ImageViewer : public QMainWindow
{
    Q_OBJECT
public:
    ImageViewer();

private:

    void createActions();

    void open();
    bool loadFile(const QString &fileName);

    QLabel *m_imageLabel;
    QMenu *m_fileMenu;
    QAction *m_openFileAction;

    double scaleFactor = 1;
};


#endif//EDGEDETECTION_IMAGEVIEWER_H
