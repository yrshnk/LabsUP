#include "car.h"

Car::Car() : model(""), speed(0), price(0.0), imagePath("")
{
}

Car::Car(const QString &model, int speed, double price, const QString &imagePath)
    : model(model), speed(speed), price(price), imagePath(imagePath)
{
}
