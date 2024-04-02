#ifndef TOUR_H
#define TOUR_H
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct Tour {
    string destination; // Название направления
    int duration; // Продолжительность поездки в минутах
    double price; // Цена
    int groupSize; // Размер группы
};

class TourList {
private:
    vector<Tour> tours;

public:
    // Добавление элемента в список
    void addTour(const Tour& newTour) {
        tours.push_back(newTour);
        sort(tours.begin(), tours.end(), [](const Tour& a, const Tour& b) {
            return a.price < b.price;
            });
    }

    // Удаление элемента по номеру позиции
    void removeTour(int position) {
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("Position is out of range");
        }
        tours.erase(tours.begin() + position);
    }

    // Получение значения элемента по номеру позиции
    Tour getTour(int position) {
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("Position is out of range");
        }
        return tours[position];
    }

    // Проверка наличия в списке тура с указанным направлением поездки
    vector<int> findToursByDestination(const string& destination) {
        vector<int> positions;
        for (int i = 0; i < tours.size(); ++i) {
            if (tours[i].destination == destination) {
                positions.push_back(i);
            }
        }
        return positions;
    }

    // Получение описаний всех туров, цена которых не превышает указанную
    vector<Tour> getToursByMaxPrice(double maxPrice) {
        vector<Tour> result;
        for (const auto& tour : tours) {
            if (tour.price <= maxPrice) {
                result.push_back(tour);
            }
        }
        return result;
    }
};
#endif