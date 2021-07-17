#include <QApplication>
#include <QPushButton>

#include "ImageViewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageViewer mainWindow;
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();

    mainWindow.show();
    return QApplication::exec();
}
