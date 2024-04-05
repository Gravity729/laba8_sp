#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Tour {// Структура, описывающая тур
    string destination; // Название направления
    int duration; // Продолжительность поездки в минутах
    double price; // Цена
    int groupSize; // Размер группы
};

class TourList {// Класс, представляющий список туров
private:
    list<Tour*> tours;

public:
    void addTour(const Tour& newTour) {// Метод добавления тура в список
        Tour* newTourPtr = new Tour(newTour);
        tours.push_back(newTourPtr);
        tours.sort([](const Tour* a, const Tour* b) {
            return a->price < b->price;
            });
    }

    void removeTour(int position) { // Метод удаления тура из списка по позиции
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("Позиция вне диапазона");
        }

        auto iter = tours.begin();
        advance(iter, position);

        delete* iter;
        tours.erase(iter);
    }

    Tour* getTour(int position) {// Метод получения тура из списка по позиции
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("Позиция вне диапазона");
        }

        auto iter = tours.begin();
        advance(iter, position);

        return *iter;
    }

    list<int> findToursByDestination(const string& destination) {  // Метод поиска позиций всех туров по названию направления
        list<int> positions;
        int index = 0;

        for (Tour* tour : tours) {
            if (tour->destination == destination) {
                positions.push_back(index);
            }
            index++;
        }
        return positions;
    }

    list<Tour*> getToursByMaxPrice(double maxPrice) {// Метод получения списка туров, цена которых не превышает заданную
        list<Tour*> result;

        for (Tour* tour : tours) {
            if (tour->price <= maxPrice) {
                result.push_back(tour);
            }
        }

        return result;
    }

    // Деструктор для освобождения памяти от туров при удалении объекта
    ~TourList() {
        for (Tour* tour : tours) {
            delete tour;
        }
    }
};

#endif