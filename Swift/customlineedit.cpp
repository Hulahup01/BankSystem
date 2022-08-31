#include "customlineedit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent)
{
    setInputMask("0000 0000 0000 0000");
}

void CustomLineEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);
    setCursorPosition(0);
}
