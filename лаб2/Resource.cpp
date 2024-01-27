#include "Resource.h"

Resource::Resource() : consumption(0), production(0), price(0) {}

//Конструктор по умолчанию инициализирует объект класса значениями по умолчанию (0) для потребления (consumption), производства (production) и цены (price).
Resource::Resource(const std::string& name, double consumption, double production, double price)
    : name(name), consumption(consumption), production(production), price(price) {} 

//Конструктор с параметрами инициализирует объект класса переданными значениями
Resource::Resource(const std::string& name, double price) : Resource(name, 0, 0, price) {}

std::string Resource::getName() const {
    return name;
}

double Resource::getConsumption() const {
    return consumption;
}

double Resource::getProduction() const {
    return production;
}

double Resource::getPrice() const {
    return price;
}

void Resource::setName(const std::string& name) {
    this->name = name;
}

void Resource::setConsumption(double consumption) {
    this->consumption = consumption;
}

void Resource::setProduction(double production) {
    this->production = production;
}

void Resource::setPrice(double price) {
    this->price = price;
}

bool Resource::operator==(const Resource& other) const { //Перегруженный оператор равенства, сравнивает ресурсы по имени.
    return name == other.name;
}

bool Resource::operator<(const Resource& other) const {
   // Перегруженный оператор меньше, который используется для сравнения ресурсов при их сортировке(например, при добавлении в отсортированный контейнер).

    return name < other.name;
}

double Resource::calculateWeeklyProfit() const { //вычисления недельной прибыли от ресурса на основе его потребления, производства и цены.

    return 7 * price;
}

void Resource::increaseTurnover(double factor) { //: Увеличивает потребление и производство ресурса на заданный коэффициент.
    consumption *= factor;
    production *= factor;
}

std::ostream& operator<<(std::ostream& os, const Resource& obj) {
    os << "Resource: " << obj.name << ", Consumption: " << obj.consumption << " kg/d, Production: "
        << obj.production << " kg/d, Price: " << obj.price << " u.e./kg";
    return os;
}
// Перегруженный оператор вывода в поток для удобного вывода информации о ресурсе в стандартный поток вывода 
