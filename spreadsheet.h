#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>
#include "ui_formdoc.h"

class Cell;

class Spreadsheet : public QTableWidget
{
    Q_OBJECT
public:
    Spreadsheet(QWidget * parent = 0);

    bool autoRecalculate() const { return autoRecalc; }
    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectedRange() const;
    void clear();
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);

public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrenRow();
    void selectCurrenColumn();
    void recalculate();
    void setAutoRecalculate(bool recalc);
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

signals:
    void modified();

private slots:
    void somethingChanged();

private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };

    Cell *cell(int row, int column) const;
    QString text(int row, int column) const;
    QString formula(int row, int column) const;
    void setFormula(int row, int column, const QString &formula);

    bool autoRecalc;
};

#endif // SPREADSHEET_H
