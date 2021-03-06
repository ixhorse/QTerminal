#ifndef QTERMWIDGET_H
#define QTERMWIDGET_H

#include "QTermScreen.h"

class QTermWidget : public QTermScreen
{
    Q_OBJECT

public:
    explicit QTermWidget(QWidget *parent = Q_NULLPTR);

public slots:
    void putData(const QByteArray &data);

signals:
    void outData(const QByteArray &data);

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    void recvChar(char ch);
    void parseParam(QVector<int> &param, int np = 1, int defval = 0);
    void flushText();
    void debug(const QByteArray &data);

private:
    void eraseText(char cmd);
    void moveCursor(char cmd);
    void setDisplay();

private:
    int m_Mode;
    QString m_Param;
    QByteArray m_Text;
};

#endif // QTERMWIDGET_H
