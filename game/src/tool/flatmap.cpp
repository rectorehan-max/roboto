#include "tool/flatmap.h"
#include <iostream>

template<typename T>
Flatmap<T>::Flatmap(int width, int height) : 
    width(width), height(height) {
}

template<typename T>
void Flatmap<T>::setGrid(std::vector<T> vec) {
    if (vec.size() > this->getSize()) {
        std::cout << "Vector size is larger than expected, grid will be set to empty \n";
        return;
    }
    if (vec.size() < this->getSize()) {
        std::cout << "Vector size is smaller than expected, grid will still be set \n";
    }
    this->vec = vec;
}

template<typename T>
const int Flatmap<T>::getWidth() {
    return width;
}

template<typename T>
const int Flatmap<T>::getHeight() {
    return height;
}

template<typename T>
void Flatmap<T>::forEachPlace(std::function<void(int x, int y, T t)> fn) {
    if (vec.empty()) return;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            T t = vec[y * width + x];
            fn(x, y, t);           
        }
    }
}

template<typename T>
int Flatmap<T>::getSize() {
    return width * height;
}

template class Flatmap<int>;
template class Flatmap<char>;
template class Flatmap<bool>;
