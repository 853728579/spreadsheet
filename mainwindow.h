#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include "ui_mainwindow.h"
#include "gotocelldialog.h"
#include "finddialog.h"

class Spreadsheet;
class FindDialog;

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();

    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString & fullFileName);

    Spreadsheet * spreadsheet;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    QStringList recentFiles;
    QString curFile;
    FindDialog * findDialog;

    enum{MaxRecentFiles = 5};
    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction * newAction;
    QAction * openAction;
    QAction * saveAction;
    QAction * saveAsAction;
    QAction * recentFileActions[MaxRecentFiles];
    QAction * exitAction;
    QAction * cutAction;
    QAction * copyAction;
    QAction * pasteAction;
    QAction * deleteAction;
    QAction * selectRowAction;
    QAction * selectColumnAction;
    QAction * selectAllAction;
    QAction * findAction;
    QAction * goToCellAction;
    QAction * recalculateAction;
    QAction * sortAction;
    QAction * showGridAction;
    QAction * autoRecalcAction;
    QAction * aboutAction;
    QAction * aboutQtAction;

    QMenu * fileMenu;
    QMenu * editMenu;
    QMenu * selectSubMenu;
    QMenu * toolsMenu;
    QMenu * optionsMenu;
    QMenu * helpMenu;
};

#endif // MAINWINDOW_H
