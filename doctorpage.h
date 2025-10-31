#ifndef DOCTORPAGE_H
#define DOCTORPAGE_H

#include <QWidget>

class DoctorPage : public QWidget {
    Q_OBJECT
public:
    explicit DoctorPage(QWidget *parent = nullptr);

signals:
    void backToLoginRequested();
};

#endif // DOCTORPAGE_H
