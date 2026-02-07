#include "fio.h" 
#include <fstream>
#include <sstream>
#include <iostream>

void printFileErr(const std::string& path) {
    std::cout << "\"" << path << "\" cannot be opened. \n"; 
}

int fio::in::loadGen_int(const std::string& path, const std::string& name) {
    std::ifstream infile(path);

    if (!infile.is_open()) {
        infile.close();
        printFileErr(path);
        return 0;
    }

    std::string line;

    while (std::getline(infile, line)) {
        std::string key;
        std::stringstream ss(line);

        std::getline(ss, key, '=');

        if (name != key) continue;

        std::string val_str;

        ss >> val_str;

        int val = 0;
        val = std::stoi(val_str);
        infile.close();
        return val;
    }
    
    infile.close();

    return 0;
}


float fio::in::loadGen_flt(const std::string& path, const std::string& name) {
    std::ifstream infile(path);

    if (!infile.is_open()) {
        infile.close();
        printFileErr(path);
        return 0.0f;
    }

    std::string line;

    while (std::getline(infile, line)) {
        std::string key;
        std::stringstream ss(line);

        std::getline(ss, key, '=');

        if (name != key) continue;

        std::string val_str;

        ss >> val_str;

        float val = 0.0f;
        val = std::stof(val_str);
        infile.close();
        return val;
    }
    
    infile.close();

    return 0.0f;
}

bool fio::in::loadGen_bool(const std::string& path, const std::string& name) {
    std::ifstream infile(path);
    bool b = false;

    if (!infile.is_open()) {
        infile.close();
        printFileErr(path);
        return b;
    }

    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string key;

        std::getline(ss, key, '=');

        if (name != key) continue;

        std::string val_str;

        ss >> val_str;

        if (val_str == "true") {
            b = true;
        } else if (val_str == "false") {
            b = false;
        } else {
            std::cout << val_str << "<- improper format. \n";
        }
    }

    infile.close();
    return b;
}

Vector2 fio::in::loadGen_vec2(const std::string& path, const std::string& name) {
    std::ifstream infile(path);
    Vector2 vec2 = { 0, 0 };

    if (!infile.is_open()) {
        infile.close();
        printFileErr(path);
        return vec2;
    }

    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line); 
        std::string key;

        std::getline(ss, key, '=');

        if (key != name) continue;
        
        char comma;

        ss >> vec2.x >> comma >> vec2.y;

    }

    infile.close();
    return vec2;
}

void fio::in::load_fmap_int(const std::string& path, Flatmap<int>& fmap) {
    int boundSize = fmap.getSize();
    std::vector<int> vec;

    std::ifstream infile(path);

    if (!infile.is_open()) { 
        printFileErr(path);
        fmap.setGrid({ });
        return;
    }

    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        int num;

        while (ss >> num) {
            vec.push_back(num);
        }
    }

    if (vec.size() != boundSize) {
        std::cout << "\"" << path << "\" does not match the expected size. \n"; 
        if (vec.size() > boundSize) {
            std::cout << "In vector size is too big... \n";
            std::cout << "Grid will be set to empty. \n";
            fmap.setGrid({ });
            return;
        } else if (vec.size() < boundSize) {
            std::cout << "In vector size it too small... \n";
            std::cout << "Grid will still be set. \n";
            fmap.setGrid(vec);
            return;
        }
    }

    fmap.setGrid(vec);
}

Sprite* fio::in::loadGen_spr_p_h(const std::string& name) {
    std::ifstream infile("../res/addspr.txt");

    if (!infile.is_open()) {
        std::cout << "../res/addspr.txt is missing \n";
        infile.close();
        return nullptr;
    }

    std::string line;

    while (std::getline(infile, line)) {

        if (line.empty()) continue;
        if (line[0] == ';') continue;

        std::stringstream ss(line);
        std::string key;

        std::getline(ss, key, '=');
        
        if (key != name) continue;

        std::string path;
        std::string width_str;
        std::string height_str;

        std::getline(ss, path, ',');
        std::getline(ss, width_str, ',');
        std::getline(ss, height_str);

        int width = std::stoi(width_str);
        int height = std::stoi(height_str);

        infile.close();

        return new Sprite(name, path, width, height);

    }
    return nullptr;
}

SpriteSheet* fio::in::loadGen_sprsheet_p_h(const std::string& name) {
    
    std::ifstream infile("../res/addsprsheet.txt");

    if (!infile.is_open()) {
        std::cout << "../res/addsprheet.txt is missing \n";
        infile.close();
        return nullptr;
    }

    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);

        if (line.empty()) continue;
        if (line[0] == ';') continue;

        std::string key;
        std::getline(ss, key, '=');

        if (name != key) continue;
        
        std::string path, frameWidth_str, frameHeight_str, numRows_str, numCols_str, maxFrames_str;

        std::getline(ss, path, ',');
        std::getline(ss, frameWidth_str, ',');
        std::getline(ss, frameHeight_str, ',');
        std::getline(ss, numRows_str, ',');
        std::getline(ss, numCols_str, ',');
        std::getline(ss, maxFrames_str);
        
        int frameWidth = std::stoi(frameWidth_str);
        int frameHeight = std::stoi(frameHeight_str);
        int numRows = std::stoi(numRows_str);
        int numCols = std::stoi(numCols_str);
        int maxFrames = std::stoi(maxFrames_str);
        return new SpriteSheet(name, path, frameWidth, frameHeight, numRows, numCols, maxFrames);
    }

    return nullptr;
}
