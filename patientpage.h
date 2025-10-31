#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H

#include <QWidget>

class PatientPage : public QWidget {
    Q_OBJECT
public:
    explicit PatientPage(QWidget *parent = nullptr);

signals:
    void backToLoginRequested();
};

#endif // PATIENTPAGE_H
