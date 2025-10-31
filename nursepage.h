#ifndef NURSEPAGE_H
#define NURSEPAGE_H

#include <QWidget>

class NursePage : public QWidget {
    Q_OBJECT
public:
    explicit NursePage(QWidget *parent = nullptr);

signals:
    void backToLoginRequested();
};

#endif // NURSEPAGE_H
