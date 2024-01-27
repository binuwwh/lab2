
#pragma once

#include "Resource.h"
#include <vector>

class ResourceTable {
private:
    std::vector<Resource> resources;

public:
    ResourceTable();
    ResourceTable(const std::vector<Resource>& resourceList);

    void addResource(const Resource& resource);
    Resource& getResource(const std::string& name); //��������� ������� �� ��� ������������
    void removeResource(const std::string& name);
    double calculateTotalProfit() const;
    void increaseTurnoverForAll(double factor); ///���������� ������� ���� �������� � ������� �� �������� �����.
    void renameResource(const std::string& oldName, const std::string& newName);
    const std::vector<Resource>& getResources() const;//����������� ������ ������������ ������� � ���������.

    ResourceTable&operator+=(const Resource& resource); //���������� ������ ������� � �������;


    friend std::ostream& operator<<(std::ostream& os, const ResourceTable& obj); //������������� �������� ������ � ����� 
    
    friend ResourceTable operator+(const ResourceTable& table1, const ResourceTable& table2);


};











