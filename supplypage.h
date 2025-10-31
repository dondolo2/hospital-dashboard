#ifndef SUPPLYPAGE_H
#define SUPPLYPAGE_H

#include <QWidget>

class SupplyPage : public QWidget {
    Q_OBJECT
public:
    explicit SupplyPage(QWidget *parent = nullptr);

signals:
    void backToLoginRequested();
};

#endif // SUPPLYPAGE_H
