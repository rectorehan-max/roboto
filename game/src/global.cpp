#include "global.h"
#include <filesystem>
#include <iostream>

Vector2 global::getCenter(Rectangle rec) {
    
    return { rec.x + rec.width * 0.5f,
             rec.y + rec.height * 0.5f 
           };
}


void global::printIsValidFile(const std::string& path_str) {
    std::filesystem::path p(path_str);

    try {
        if (std::filesystem::exists(p) && std::filesystem::is_regular_file(p)) {
            std::cout << path_str << " : is valid. \n";
        } 
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "File system Error: " << e.what() << std::endl;
    }
}

