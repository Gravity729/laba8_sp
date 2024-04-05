#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Tour {// ���������, ����������� ���
    string destination; // �������� �����������
    int duration; // ����������������� ������� � �������
    double price; // ����
    int groupSize; // ������ ������
};

class TourList {// �����, �������������� ������ �����
private:
    list<Tour*> tours;

public:
    void addTour(const Tour& newTour) {// ����� ���������� ���� � ������
        Tour* newTourPtr = new Tour(newTour);
        tours.push_back(newTourPtr);
        tours.sort([](const Tour* a, const Tour* b) {
            return a->price < b->price;
            });
    }

    void removeTour(int position) { // ����� �������� ���� �� ������ �� �������
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("������� ��� ���������");
        }

        auto iter = tours.begin();
        advance(iter, position);

        delete* iter;
        tours.erase(iter);
    }

    Tour* getTour(int position) {// ����� ��������� ���� �� ������ �� �������
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("������� ��� ���������");
        }

        auto iter = tours.begin();
        advance(iter, position);

        return *iter;
    }

    list<int> findToursByDestination(const string& destination) {  // ����� ������ ������� ���� ����� �� �������� �����������
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

    list<Tour*> getToursByMaxPrice(double maxPrice) {// ����� ��������� ������ �����, ���� ������� �� ��������� ��������
        list<Tour*> result;

        for (Tour* tour : tours) {
            if (tour->price <= maxPrice) {
                result.push_back(tour);
            }
        }

        return result;
    }

    // ���������� ��� ������������ ������ �� ����� ��� �������� �������
    ~TourList() {
        for (Tour* tour : tours) {
            delete tour;
        }
    }
};

#endif