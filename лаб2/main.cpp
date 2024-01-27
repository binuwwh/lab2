#include "ResourceTable.h"
#include <iostream>

int main() {
    // Создаем экземпляр таблицы ресурсов
    ResourceTable resourceTable;

    // 1. Пользователь вводит данные для metal, wood, gold
    std::cout << "Enter information for Metal resource:\n";
    std::string metalName;
    double metalPrice;
    std::cout << "Name: ";
    std::cin >> metalName;
    std::cout << "Price: ";
    std::cin >> metalPrice;
    Resource metal(metalName, metalPrice);

    std::cout << "Enter information for Wood resource:\n";
    std::string woodName;
    double woodPrice;
    double woodConsumption;
    double woodProduction;
    std::cout << "Name: ";
    std::cin >> woodName;
    std::cout << "Price: ";
    std::cin >> woodPrice;
    std::cout << "Consumption: ";
    std::cin >> woodConsumption;
    std::cout << "Production: ";
    std::cin >> woodProduction;
    Resource wood(woodName, woodConsumption, woodProduction, woodPrice);

    std::cout << "Enter information for Gold resource:\n";
    std::string goldName;
    double goldPrice;
    double goldConsumption;
    double goldProduction;
    std::cout << "Name: ";
    std::cin >> goldName;
    std::cout << "Price: ";
    std::cin >> goldPrice;
    std::cout << "Consumption: ";
    std::cin >> goldConsumption;
    std::cout << "Production: ";
    std::cin >> goldProduction;
    Resource gold(goldName, goldConsumption, goldProduction, goldPrice);

    // 2. Добавление ресурсов в таблицу
    resourceTable += metal;
    resourceTable += wood;
    resourceTable += gold;

    // 3. Вывод состояния таблицы ресурсов
    std::cout << "Initial Resource Table:\n" << resourceTable << std::endl;

    // 4. Добавление нового ресурса в таблицу
    std::cout << "Enter information for Silver resource (to add a new resource):\n";
    std::string silverName;
    double silverPrice;
    double silverConsumption;
    double silverProduction;
    std::cout << "Name: ";
    std::cin >> silverName;
    std::cout << "Price: ";
    std::cin >> silverPrice;
    std::cout << "Consumption: ";
    std::cin >> silverConsumption;
    std::cout << "Production: ";
    std::cin >> silverProduction;
    Resource silver(silverName, silverConsumption, silverProduction, silverPrice);
    resourceTable += silver;

    // 5. Удаление ресурса с заданным наименованием из таблицы
    std::cout << "Enter the name of the resource to remove from the table: ";
    std::string resourceToRemove;
    std::cin >> resourceToRemove;
    try {
        resourceTable.removeResource(resourceToRemove);
        std::cout << "Resource table after removing " << resourceToRemove << ":\n" << resourceTable << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // 6. Вычисление общей прибыльности по всем ресурсам
    double totalProfit = resourceTable.calculateTotalProfit();
    std::cout << "Total profit of the resource table: " << totalProfit << " u.e." << std::endl;

    // 7. Увеличение оборота всех ресурсов в заданное число раз
    double turnoverFactor;
    std::cout << "Enter the turnover factor: ";
    std::cin >> turnoverFactor;
    resourceTable.increaseTurnoverForAll(turnoverFactor);
    std::cout << "Resource table after increasing turnover for all resources:\n" << resourceTable << std::endl;

    // 8. Переименование заданного ресурса (передаются старое и новое наименования)
    std::string oldResourceName, newResourceName;
    std::cout << "Enter the name of the resource to rename: ";
    std::cin >> oldResourceName;
    std::cout << "Enter the new name for the resource: ";
    std::cin >> newResourceName;
    try {
        resourceTable.renameResource(oldResourceName, newResourceName);
        std::cout << "Resource table after renaming " << oldResourceName << " to " << newResourceName << ":\n"
            << resourceTable << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // 9. Сравнение двух ресурсов по наименованию
    std::cout << "Enter two resource names to compare:\n";
    std::string resourceName1, resourceName2;
    std::cout << "Name 1: ";
    std::cin >> resourceName1;
    std::cout << "Name 2: ";
    std::cin >> resourceName2;
    Resource resource1 = resourceTable.getResource(resourceName1);
    Resource resource2 = resourceTable.getResource(resourceName2);
    if (resource1 < resource2) {
        std::cout << resourceName1 << " is less than " << resourceName2 << " in alphabetical order.\n";
    }
    else if (resource1 == resource2) {
        std::cout << resourceName1 << " and " << resourceName2 << " have the same name.\n";
    }
    else {
        std::cout << resourceName1 << " is greater than " << resourceName2 << " in alphabetical order.\n";
    }

    // 10. Вычисление ориентировочной прибыльности (в у.е.) ресурса за неделю
    std::cout << "Enter the name of the resource to calculate weekly profit: ";
    std::string profitResourceName;
    std::cin >> profitResourceName;
    try {
        Resource profitResource = resourceTable.getResource(profitResourceName);
        double weeklyProfit = profitResource.calculateWeeklyProfit();
        std::cout << "Weekly profit for " << profitResourceName << ": " << weeklyProfit << " u.e.\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
