#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QDirIterator>
#include <QDir>
#include <QProcess>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <QFileSystemModel>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>
#include <QModelIndex>
#include <string.h>
#include <string>
#include <QListWidget>
#include <QAction>
#include <QDesktopServices>
#include <QTextBrowser>
#include "workingdirectorydialog.h"
#include "selectdialog.h"
#include <QPainter>
#include "adddialog.h"
#include <Git_DLL.h>
#include <QStandardItemModel>
#include <QStandardItem>
#include <qstyleditemdelegate.h>
#include <qdirmodel.h>
#include <QtCore>
#include "checkindialog.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QColor checkedOutColor;
    QString workingDirPath = "";
    QString workingDirName = "";
    QString oldName = "";
    QFile vssFile;
    QTextEdit *fileEditor;
    int filesColumnCount = 2;
    void showMessage(QString, QString, QString);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;

public slots:
    void showContextMenuFiles(const QPoint &pos);
    void showContextMenuDirs(const QPoint &pos);
    void expandFolder(QTreeWidgetItem *);
    void displayOnlyFiles(QString, vector<string>);
    void displayFilesAndFolders(QTreeWidgetItem *, QString, vector<string>);
    void menuEditClicked();
    void menuFileClicked();
    void menuSourceSafeClicked();
    void takeAction(QAction *);
    void getSelectedName(QString);
    void getDeselectedName(QString);
    void fileClicked();
    void folderClicked();

    //action-----------------------------------
    void exportFile();
    void addFiles();
    void setWorkingFolder();
    void checkIn();
    void checkOut();
    void selectFile();
    void selectAllFiles();
    void editFile();
    void viewFile();
    void deleteSelected();
    void renameSelected();
    void renameFileFinished(QTreeWidgetItem *);
    void renameFolderFinished(QTreeWidgetItem *);
    void refreshWidgets();
    void help();
    void savePressed();
};

#endif // MAINWINDOW_H

