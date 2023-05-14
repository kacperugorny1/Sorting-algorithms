#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "introsort.h"
#include "mergesort.h"
#include "quicksort.h"

#define len 2500000

struct movie {
    int num;
    std::string title;
    double rating;

    movie(std::string title, double rating, int num) { this->num = num; this->title = title; this->rating = rating; }
    movie() { num = 0; title = ""; rating = 0; };
    movie& operator=(const movie& other) {
        rating = other.rating;
        title = other.title;
        num = other.num;
        return *this;
    };
};
bool operator< (const movie& movie1, const movie& movie2) { return movie1.rating < movie2.rating; }
bool operator> (const movie& movie1, const movie& movie2) { return movie1.rating > movie2.rating; }
bool operator<= (const movie& movie1, const movie& movie2) { return movie1.rating <= movie2.rating; }
bool operator>= (const movie& movie1, const movie& movie2) { return movie1.rating >= movie2.rating; }

template<typename T>
int isSorted(T array[], int l, int r) {
    T temp = array[l];
    for (int i = l; i <= r; ++i) {
        if (temp > array[i])
            return 0;
        temp = array[i];
    }
    return 1;
}

void loadData(std::string link, movie movies[], int length) {
    std::string line = "";
    std::ifstream file_stream(link);
    size_t coma = 0;
    int num = 0;
    std::string title = "";
    double rating = 0;
    int skip = 0;
    if (!file_stream.is_open())
        return;
    for (int i = 0; i < length; ++i) {
        try {
            if (!file_stream.good())
                break;
            std::getline(file_stream, line);
            coma = line.find(',');
            num = std::stoi(line.substr(0, coma));
            line = line.substr(coma + 1, line.length());
            if (line[0] == '"') {
                line = line.substr(1, line.length());
                coma = line.find('"');
                title = line.substr(0, coma);
                line = line.substr(coma + 2, line.length());
            }
            else {
                coma = line.find(',');
                title = line.substr(0, coma);
                line = line.substr(coma + 1, line.length());
            }
            rating = std::stod(line.substr(0, line.length()));
            movies[i].rating = rating;
            movies[i].num = num;
            movies[i].title = title;
        }
        catch (...) {
            skip++;
            --i;
            continue;
        }
    }
    std::cout << "\n\nPominieto " << skip << " wynikow " << std::endl;

}



using namespace std::chrono;

int main() {
    int no_elements = 0;
    std::string x = "";
    movie* movies = new movie[len];
    std::cout << "How many elements u want sort: ";
    std::cin >> no_elements;


    loadData("data.csv", movies, no_elements);
    std::cout << "MERGESORT : \n";
    auto start = high_resolution_clock::now();
    mergeSort(movies, 0, no_elements - 1);
    auto time = high_resolution_clock::now() - start;
    auto time_in_micsec = (double)duration_cast<milliseconds>(time).count();
    std::cout << "Time passed: " << time_in_micsec << " milliseconds" << std::endl;
    std::cout << "Is sorted? : " << isSorted(movies, 0, no_elements - 1) << std::endl << std::endl;


    loadData("data.csv", movies, no_elements);
    std::cout << "INTROSORT : \n";
    start = high_resolution_clock::now();
    introSort(movies, 0, no_elements - 1);
    time = high_resolution_clock::now() - start;
    time_in_micsec = (double)duration_cast<milliseconds>(time).count();
    std::cout << "Time passed: " << time_in_micsec << " milliseconds" << std::endl;
    std::cout << "Is sorted? : " << isSorted(movies, 0, no_elements - 1) << std::endl << std::endl;



    loadData("data.csv", movies, no_elements);
    std::cout << "QUICKSORT : \n";
    start = high_resolution_clock::now();
    quickSort(movies, 0, no_elements - 1);
    time = high_resolution_clock::now() - start;
    time_in_micsec = (double)duration_cast<milliseconds>(time).count();
    std::cout << "Time passed: " << time_in_micsec << " milliseconds" << std::endl;
    std::cout << "Is sorted? : " << isSorted(movies, 0, no_elements - 1) << std::endl << std::endl;


    

    std::cin >> no_elements;
    std::cin >> no_elements;
    std::cin >> no_elements;


    return 0;
}