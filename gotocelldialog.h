#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include "ui_gotocelldialog.h"
#include "gotocelldialog.h"

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget * parent);
    ~GoToCellDialog();

    QString getLineEdit();

private slots:
    void on_lineEdit_textChanged();

private:
    Ui::GoToCellDialog * ui;
};

#endif // GOTOCELLDIALOG_H
