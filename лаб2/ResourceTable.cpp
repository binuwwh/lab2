#include "ResourceTable.h"
#include <algorithm>

ResourceTable::ResourceTable() {}

ResourceTable::ResourceTable(const std::vector<Resource>& resourceList) : resources(resourceList) {
    std::sort(resources.begin(), resources.end());
}

void ResourceTable::addResource(const Resource& resource) { // ��������� ������ � �������.���� ������ � ����� �� ������ ��� ����������, ���������� ��(����������� �������� ����������� � ������������, ������� ����������� ����).
    auto it = std::lower_bound(resources.begin(), resources.end(), resource); //��� ���������� �������, �� ������� ����� �������� ������ ���, ����� ������� �� ����� ��� ��������.
    if (it != resources.end() && *it == resource) {
        it->setConsumption(it->getConsumption() + resource.getConsumption());
        it->setProduction(it->getProduction() + resource.getProduction());
        it->setPrice(std::min(it->getPrice(), resource.getPrice()));
    }
    //��� ������ � ����� ������ ��� ����������, ���������� �� (����������� �������� ����������� � ������������, ������� ����������� ����).
    else {
        resources.insert(it, resource); //���� ��� � ����� ������ ��������� ����� ������
    }
}

Resource& ResourceTable::getResource(const std::string& name) { // ��������� ������ �� ������ �� ��� �����.
    auto it = std::lower_bound(resources.begin(), resources.end(), Resource(name, 0, 0, 0));
    if (it != resources.end() && it->getName() == name) { //���� ������ � ��������� ������ ������, ���������� ������ �� ����
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
    } //���� ������ � ��������� ������ ������, ������� ��� ���, ���������� ���������� 

    else {
        throw std::out_of_range("Resource not found in the table.");
    }
}

double ResourceTable::calculateTotalProfit() const {
    double totalProfit = 0;
    for (const auto& resource : resources) { //�������� �� ���� �������� � ������� � ��������� �� ��������� �������.
        totalProfit += resource.calculateWeeklyProfit();
    }
    return totalProfit;
}

void ResourceTable::increaseTurnoverForAll(double factor) {
    for (auto& resource : resources) { //���������� ������� ���� �������� � ������� �� �������� �����������.
        resource.increaseTurnover(factor);
    }
}

void ResourceTable::renameResource(const std::string& oldName, const std::string& newName) {
    auto it = std::lower_bound(resources.begin(), resources.end(), Resource(oldName, 0, 0, 0));
    if (it != resources.end() && it->getName() == oldName) {
        it->setName(newName); // ��������� ����� �������
        std::sort(resources.begin(), resources.end()); // ��������� ���������� �������
    }
    else {
        throw std::out_of_range("Resource not found in the table.");
    }
}


ResourceTable& ResourceTable::operator+=(const Resource& resource) { // ������������� �������� += ��� �������� ���������� ������� � �������.
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
    ResourceTable result = table1; // �������� ������ �������

    // ��������� ������� ������ ������� � ���������
    for (const auto& resource : table2.resources) {
        result.addResource(resource);
    }

    return result;
}
const std::vector<Resource>& ResourceTable::getResources() const {
    return resources;
}
