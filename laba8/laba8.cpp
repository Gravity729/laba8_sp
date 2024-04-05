#include "tour.h"
#include <iostream>

int main() {
    system("chcp 1251"); // Установка кодовой страницы консоли
    setlocale(LC_ALL, "Russian"); // Установка локали на русский язык

    TourList tourList;

    Tour tour1 = { "Париж", 120, 500.50, 10 };
    Tour tour2 = { "Рим", 90, 400.75, 15 };
    Tour tour3 = { "Лондон", 150, 600.25, 8 };

    tourList.addTour(tour1);
    tourList.addTour(tour2);
    tourList.addTour(tour3);

    // Проверка добавления и вывод элементов
    try {
        cout << "Добавлены туры:" << endl;
        for (int i = 0; i < 3; ++i) {
            Tour* currentTour = tourList.getTour(i);
            cout << "Тур " << i << ": " << currentTour->destination
                << ", продолжительность поездки в минутах: " << currentTour->duration
                << ", цена: " << currentTour->price
                << ", размер группы: " << currentTour->groupSize << endl;
        }

        cout << "-------------------------------------------------" << endl;

        cout << "Удаление тура «Париж»: ";
        // Удаление элемента
        try {
            tourList.removeTour(1);
            cout << "удаление завершено успешно" << endl;
        }
        catch (const out_of_range& e) {
            cerr << "сбой удаления" << endl;
        }

        cout << "-------------------------------------------------" << endl;

        // Вывод оставшихся элементов
        cout << "Оставшиеся туры:" << endl;
        for (int i = 0; i < 2; ++i) {
            Tour* currentTour = tourList.getTour(i);
            cout << "Тур " << i << ": " << currentTour->destination << endl;
        }

        cout << "-------------------------------------------------" << endl;

        // Поиск тура по направлению
        cout << "Поиск «Париж»:" << endl;
        list<int> positions = tourList.findToursByDestination("Париж");
        if (positions.empty()) {
            cout << "Тур не найден." << endl;
        }
        else {
            cout << "«Париж» найдено в позиции:";
            for (int pos : positions) {
                cout << " " << pos;
            }
            cout << endl;
        }

        cout << "-------------------------------------------------" << endl;

        cout << "Поиск «Рим»:" << endl;
        positions = tourList.findToursByDestination("Рим");
        if (positions.empty()) {
            cout << "Тур не найден." << endl;
        }
        else {
            cout << "«Рим» найдено в позиции:";
            for (int pos : positions) {
                cout << " " << pos;
            }
            cout << endl;
        }

        cout << "-------------------------------------------------" << endl;

        // Получение туров с ценой не выше заданной
        cout << "Туры стоимостью не более 550,00:" << endl;
        list<Tour*> cheapTours = tourList.getToursByMaxPrice(550.00);
        for (Tour* tour : cheapTours) {
            cout << tour->destination << " - Цена: " << tour->price << endl;
        }
    }
    catch (const out_of_range& e) {
        cerr << "Исключение вне диапазона: " << e.what() << endl;
    }

    return 0;
}