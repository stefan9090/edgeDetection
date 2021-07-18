//
// Created by stefan on 7/16/21.
//

#include "ImageViewer.h"

#include <iostream>

#include <QFileDialog>
#include <QGuiApplication>
#include <QImageReader>
#include <QImageWriter>
#include <QMenuBar>
#include <QMessageBox>
#include <QStandardPaths>

ImageViewer::ImageViewer() :
    m_imageLabel(new QLabel)
{
    setCentralWidget(m_imageLabel);

    m_imageLabel->setBackgroundRole(QPalette::Base);
    m_imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_imageLabel->setScaledContents(true);

    setWindowTitle(tr("Dock Widgets"));

    createActions();

    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_openFileAction);

    //    auto *menuBar = new QMenuBar(nullptr);

    //    QMenu *fileMenu = menuBar->addMenu(tr("&File"));


    //    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog)
    {
        firstDialog                         = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
                                                      ? QImageReader::supportedMimeTypes()
                                                      : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    dialog.setAcceptMode(acceptMode);
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void ImageViewer::open()
{
    std::cout << "Load file called\n";

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);

    const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());

    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();

        for (auto &file : fileNames)
        {
            std::cout << file.toStdString() << std::endl;
        }

    }
    else
    {
        std::cout << "Something wnet wrong\n";
    }


    //    QFileDialog dialog(this, tr("Open File"));
    //    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
    //
    //    dialog.exec();

    //    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().constFirst())) {}
}

bool ImageViewer::loadFile(const QString &fileName)
{
    return true;
    //    QImageReader reader(fileName);
    //    reader.setAutoTransform(true);
    //    const QImage newImage = reader.read();
    //    if (newImage.isNull()) {
    //        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
    //                                 tr("Cannot load %1: %2")
    //                                         .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
    //        return false;
    //    }
    //    scaleFactor = 1.0;
    //
    //    return true;
    //    scrollArea->setVisible(true);
    //    printAct->setEnabled(true);
    //    fitToWindowAct->setEnabled(true);
    //    updateActions();
    //
    //    if (!fitToWindowAct->isChecked())
    //        imageLabel->adjustSize();
}
void ImageViewer::createActions()
{
    m_openFileAction = new QAction(tr("&Open"), this);
    m_openFileAction->setStatusTip(tr("Open a new file"));

    connect(m_openFileAction, &QAction::triggered, this, &ImageViewer::open);
}
