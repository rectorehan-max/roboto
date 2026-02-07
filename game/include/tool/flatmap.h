#pragma once
#include <vector>
#include <functional>

template<typename T>
class Flatmap {
public:
    Flatmap(int width, int height);

    void setGrid(std::vector<T> vec);
    const int getWidth();
    const int getHeight();

    void forEachPlace(std::function<void(int x, int y, T t)> fn);
    int getSize();

private:
    const int width;
    const int height;
    std::vector<T> vec;
};

