#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include "tool/flatmap.h"
#include "tool/sprite.h"
#include "tool/spritesheet.h"

namespace fio {
    namespace in {
        int loadGen_int(const std::string& path, const std::string& name);
        float loadGen_flt(const std::string& path, const std::string& name);
        bool loadGen_bool(const std::string& path, const std::string& name);
        Vector2 loadGen_vec2(const std::string& path, const std::string& name);

        void load_fmap_int(const std::string& path, Flatmap<int>& fmap);

        Sprite* loadGen_spr_p_h(const std::string& name);
        SpriteSheet* loadGen_sprsheet_p_h(const std::string& name);
    }

    namespace out {
        // this is going to be used for saving. 
    }

}
