#include "ui_finddialog.h"
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    :QDialog(parent)
{
    setupUi(this);
}
void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive;

    if (backwardCheckBox->isChecked())
    {
        emit findPrevious(text, cs);
    }else{
        emit findNext(text, cs);
    }
}
void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
