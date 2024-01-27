#include "ResourceTable.h"
#include <algorithm>

ResourceTable::ResourceTable() {}

ResourceTable::ResourceTable(const std::vector<Resource>& resourceList) : resources(resourceList) {
    std::sort(resources.begin(), resources.end());
}

void ResourceTable::addResource(const Resource& resource) { // ƒобавл€ет ресурс в таблицу.≈сли ресурс с таким же именем уже существует, объедин€ет их(увеличивает значени€ потреблени€ и производства, выбира€ минимальную цену).
    auto it = std::lower_bound(resources.begin(), resources.end(), resource); //дл€ нахождени€ позиции, на которую можно вставить ресурс так, чтобы пор€док по имени был сохранен.
    if (it != resources.end() && *it == resource) {
        it->setConsumption(it->getConsumption() + resource.getConsumption());
        it->setProduction(it->getProduction() + resource.getProduction());
        it->setPrice(std::min(it->getPrice(), resource.getPrice()));
    }
    //сли ресурс с таким именем уже существует, объедин€ет их (увеличивает значени€ потреблени€ и производства, выбира€ минимальную цену).
    else {
        resources.insert(it, resource); //если нет с таким именем вставл€ет новый ресурс
    }
}

Resource& ResourceTable::getResource(const std::string& name) { // получени€ ссылки на ресурс по его имени.
    auto it = std::lower_bound(resources.begin(), resources.end(), Resource(name, 0, 0, 0));
    if (it != resources.end() && it->getName() == name) { //≈сли ресурс с указанным именем найден, возвращает ссылку на него
        return *it;
    }
    else {
        throw std::out_of_range("Resource not found in the table.");
    }
}

void ResourceTable::removeResource(const std::string& name) {
    auto it = std::lower_bound(resources.begin(), resources.end(), Resource(name, 0, 0, 0));
    if (it != resources.end() && it->getName() == name) {
        resources.erase(it);
    } //≈сли ресурс с указанным именем найден, удал€ет его или, генерирует исключение 

    else {
        throw std::out_of_range("Resource not found in the table.");
    }
}

double ResourceTable::calculateTotalProfit() const {
    double totalProfit = 0;
    for (const auto& resource : resources) { //ѕроходит по всем ресурсам в таблице и суммирует их недельные прибыли.
        totalProfit += resource.calculateWeeklyProfit();
    }
    return totalProfit;
}

void ResourceTable::increaseTurnoverForAll(double factor) {
    for (auto& resource : resources) { //увеличени€ оборота всех ресурсов в таблице на заданный коэффициент.
        resource.increaseTurnover(factor);
    }
}

void ResourceTable::renameResource(const std::string& oldName, const std::string& newName) {
    auto it = std::lower_bound(resources.begin(), resources.end(), Resource(oldName, 0, 0, 0));
    if (it != resources.end() && it->getName() == oldName) {
        it->setName(newName); // »зменение имени ресурса
        std::sort(resources.begin(), resources.end()); // ѕовторна€ сортировка вектора
    }
    else {
        throw std::out_of_range("Resource not found in the table.");
    }
}


ResourceTable& ResourceTable::operator+=(const Resource& resource) { // ѕерегруженный оператор += дл€ удобного добавлени€ ресурса в таблицу.
    addResource(resource);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ResourceTable& obj) {
    os << "Resource Table:\n";
    for (const auto& resource : obj.resources) {
        os << resource << '\n';
    }
    return os;
}
ResourceTable operator+(const ResourceTable& table1, const ResourceTable& table2) {
    ResourceTable result = table1; //  опируем первую таблицу

    // ƒобавл€ем ресурсы второй таблицы в результат
    for (const auto& resource : table2.resources) {
        result.addResource(resource);
    }

    return result;
}
const std::vector<Resource>& ResourceTable::getResources() const {
    return resources;
}
