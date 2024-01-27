#pragma once

#include <iostream>
#include <string>

class Resource {
private:
    std::string name;
    double consumption;
    double production;
    double price;

public:
    Resource();
    Resource(const std::string& name, double consumption, double production, double price);
    Resource(const std::string& name, double price);

    // ����� ��� ���������
    std::string getName() const;
    double getConsumption() const;
    double getProduction() const;
    double getPrice() const;

    //����� ��� ��������� 
    void setName(const std::string& name);
    void setConsumption(double consumption);
    void setProduction(double production);
    void setPrice(double price);

    bool operator==(const Resource& other) const; // ������������� �������� ���������
    bool operator<(const Resource& other) const;

    double calculateWeeklyProfit() const;
    void increaseTurnover(double factor);

    friend std::ostream& operator<<(std::ostream& os, const Resource& obj);
    // ������������� ������� ���������� ��������� ������ � �����
};
