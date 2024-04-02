#ifndef TOUR_H
#define TOUR_H
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct Tour {
    string destination; // �������� �����������
    int duration; // ����������������� ������� � �������
    double price; // ����
    int groupSize; // ������ ������
};

class TourList {
private:
    vector<Tour> tours;

public:
    // ���������� �������� � ������
    void addTour(const Tour& newTour) {
        tours.push_back(newTour);
        sort(tours.begin(), tours.end(), [](const Tour& a, const Tour& b) {
            return a.price < b.price;
            });
    }

    // �������� �������� �� ������ �������
    void removeTour(int position) {
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("Position is out of range");
        }
        tours.erase(tours.begin() + position);
    }

    // ��������� �������� �������� �� ������ �������
    Tour getTour(int position) {
        if (position < 0 || position >= tours.size()) {
            throw out_of_range("Position is out of range");
        }
        return tours[position];
    }

    // �������� ������� � ������ ���� � ��������� ������������ �������
    vector<int> findToursByDestination(const string& destination) {
        vector<int> positions;
        for (int i = 0; i < tours.size(); ++i) {
            if (tours[i].destination == destination) {
                positions.push_back(i);
            }
        }
        return positions;
    }

    // ��������� �������� ���� �����, ���� ������� �� ��������� ���������
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