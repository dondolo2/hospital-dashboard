#ifndef HRPAGE_H
#define HRPAGE_H

#include <QWidget>

class HRPage : public QWidget {
    Q_OBJECT
public:
    explicit HRPage(QWidget *parent = nullptr);

signals:
    void backToLoginRequested();
};

#endif // HRPAGE_H
