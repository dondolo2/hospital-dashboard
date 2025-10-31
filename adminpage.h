#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>

class AdminPage : public QWidget {
    Q_OBJECT
public:
    explicit AdminPage(QWidget *parent = nullptr);

signals:
    void backToLoginRequested();
};

#endif // ADMINPAGE_H
