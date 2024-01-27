
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
    Resource& getResource(const std::string& name); //получение ресурса по его наименованию
    void removeResource(const std::string& name);
    double calculateTotalProfit() const;
    void increaseTurnoverForAll(double factor); ///увеличения оборота всех ресурсов в таблице на заданное число.
    void renameResource(const std::string& oldName, const std::string& newName);
    const std::vector<Resource>& getResources() const;//константную версию операторации доступа к описателю.

    ResourceTable&operator+=(const Resource& resource); //добавление нового ресурса в таблицу;


    friend std::ostream& operator<<(std::ostream& os, const ResourceTable& obj); //перегружающая оператор вывода в поток 
    
    friend ResourceTable operator+(const ResourceTable& table1, const ResourceTable& table2);


};











