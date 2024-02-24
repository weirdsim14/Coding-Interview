#include <iostream>
#include <memory>

class Car {
    public:
        std::string color;

        Car(std::string c) : color(c){}

        void start(){
            std::cout << " The " << color << " car has started" << std::endl;
        }
        std::string getColor() const{
            return color;}
};

int main()
{
    std::unique_ptr<Car> pCar = std::make_unique<Car> ("red");

    pCar->start();
    std::cout << "The car's color is " << pCar->color << "." << std::endl;

    return 0;
}