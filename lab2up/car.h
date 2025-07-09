#ifndef CAR_H
#define CAR_H

#include <QString>

class Car
{
public:
    Car();
    Car(const QString &model, int speed, double price, const QString &imagePath);

    QString model;
    int speed;
    double price;
    QString imagePath;
};

#endif // CAR_H
