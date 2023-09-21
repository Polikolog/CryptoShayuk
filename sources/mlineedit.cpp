#include "mlineedit.h"

MLineEdit::MLineEdit(QWidget* parent) : QLineEdit(parent)
{

}

void MLineEdit::pushString()
{
    emit getString(this->text(), this->objectName());
}
