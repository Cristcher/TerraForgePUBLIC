#include "coloringVariants.hpp"

void colorScheme1(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.6667f) {
        pixels[index] = 179; pixels[index + 1] = 249; pixels[index + 2] = 147;
    }
    else if (val >= 0.3333f) {
        pixels[index] = 148; pixels[index + 1] = 206; pixels[index + 2] = 122;
    }
    else if (val >= 0.0f) {
        pixels[index] = 118; pixels[index + 1] = 164; pixels[index + 2] = 97;
    }
    else if (val >= -0.3333f) {
        pixels[index] = 87; pixels[index + 1] = 121; pixels[index + 2] = 72;
    }
    else if (val >= -0.6667f) {
        pixels[index] = 57; pixels[index + 1] = 79; pixels[index + 2] = 47;
    }
    else {
        pixels[index] = 26; pixels[index + 1] = 36; pixels[index + 2] = 22;
    }
    pixels[index + 3] = 255; // Alpha channel
}

void colorScheme2(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.6667f) {
        pixels[index] = 0; pixels[index + 1] = 133; pixels[index + 2] = 133;
    }
    else if (val >= 0.3333f) {
        pixels[index] = 116; pixels[index + 1] = 168; pixels[index + 2] = 146;
    }
    else if (val >= 0.0f) {
        pixels[index] = 251; pixels[index + 1] = 242; pixels[index + 2] = 196;
    }
    else if (val >= -0.3333f) {
        pixels[index] = 230; pixels[index + 1] = 201; pixels[index + 2] = 148;
    }
    else if (val >= -0.6667f) {
        pixels[index] = 204; pixels[index + 1] = 122; pixels[index + 2] = 61;
    }
    else {
        pixels[index] = 196; pixels[index + 1] = 83; pixels[index + 2] = 53;
    }
    pixels[index + 3] = 255; // Alpha channel
}

void colorScheme3(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.6667f) {
        pixels[index] = 108; pixels[index + 1] = 88; pixels[index + 2] = 241;
    }
    else if (val >= 0.3333f) {
        pixels[index] = 89; pixels[index + 1] = 72; pixels[index + 2] = 198;
    }
    else if (val >= 0.0f) {
        pixels[index] = 70; pixels[index + 1] = 57; pixels[index + 2] = 156;
    }
    else if (val >= -0.3333f) {
        pixels[index] = 51; pixels[index + 1] = 41; pixels[index + 2] = 113;
    }
    else if (val >= -0.6667f) {
        pixels[index] = 32; pixels[index + 1] = 26; pixels[index + 2] = 71;
    }
    else {
        pixels[index] = 13; pixels[index + 1] = 10; pixels[index + 2] = 28;
    }
    pixels[index + 3] = 255; // Alpha channel
}

void colorScheme4(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.6667f) {
        pixels[index] = 46; pixels[index + 1] = 84; pixels[index + 2] = 147;
    }
    else if (val >= 0.3333f) {
        pixels[index] = 0; pixels[index + 1] = 117; pixels[index + 2] = 145;
    }
    else if (val >= 0.0f) {
        pixels[index] = 48; pixels[index + 1] = 130; pixels[index + 2] = 133;
    }
    else if (val >= -0.3333f) {
        pixels[index] = 79; pixels[index + 1] = 165; pixels[index + 2] = 188;
    }
    else if (val >= -0.6667f) {
        pixels[index] = 155; pixels[index + 1] = 194; pixels[index + 2] = 201;
    }
    else {
        pixels[index] = 230; pixels[index + 1] = 233; pixels[index + 2] = 238;
    }
    pixels[index + 3] = 255; // Alpha channel
}

void colorScheme5(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.8462f) {
        pixels[index] = 200; pixels[index + 1] = 36; pixels[index + 2] = 61;
    }
    else if (val >= 0.6923f) {
        pixels[index] = 242; pixels[index + 1] = 114; pixels[index + 2] = 79;
    }
    else if (val >= 0.5385f) {
        pixels[index] = 246; pixels[index + 1] = 160; pixels[index + 2] = 73;
    }
    else if (val >= 0.3846f) {
        pixels[index] = 255; pixels[index + 1] = 197; pixels[index + 2] = 137;
    }
    else if (val >= 0.2308f) {
        pixels[index] = 254; pixels[index + 1] = 226; pixels[index + 2] = 152;
    }
    else if (val >= 0.0769f) {
        pixels[index] = 254; pixels[index + 1] = 249; pixels[index + 2] = 181;
    }
    else if (val >= -0.0769f) {
        pixels[index] = 172; pixels[index + 1] = 217; pixels[index + 2] = 174;
    }
    else if (val >= -0.2308f) {
        pixels[index] = 76; pixels[index + 1] = 173; pixels[index + 2] = 146;
    }
    else if (val >= -0.3846f) {
        pixels[index] = 210; pixels[index + 1] = 238; pixels[index + 2] = 250;
    }
    else if (val >= -0.5385f) {
        pixels[index] = 169; pixels[index + 1] = 227; pixels[index + 2] = 247;
    }
    else if (val >= -0.6923f) {
        pixels[index] = 108; pixels[index + 1] = 206; pixels[index + 2] = 245;
    }
    else if (val >= -0.8462f) {
        pixels[index] = 1; pixels[index + 1] = 195; pixels[index + 2] = 244;
    }
    else {
        pixels[index] = 0; pixels[index + 1] = 164; pixels[index + 2] = 225;
    }
    pixels[index + 3] = 255; // Alpha channel
}


void colorScheme6(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.9f && val <= 1.0f) {
        // Very dark gray color
        pixels[index] = 32;
        pixels[index + 1] = 32;
        pixels[index + 2] = 32;
    } else if (val >= 0.8f && val < 0.9f) {
        // Dark gray color
        pixels[index] = 64;
        pixels[index + 1] = 64;
        pixels[index + 2] = 64;
    } else if (val >= 0.7f && val < 0.8f) {
        // Medium dark gray color
        pixels[index] = 96;
        pixels[index + 1] = 96;
        pixels[index + 2] = 96;
    } else if (val >= 0.6f && val < 0.7f) {
        // Gray color
        pixels[index] = 128;
        pixels[index + 1] = 128;
        pixels[index + 2] = 128;
    } else if (val >= 0.47f && val < 0.6f) {
        // Light gray color
        pixels[index] = 160;
        pixels[index + 1] = 160;
        pixels[index + 2] = 160;
    } else if (val >= 0.3f && val < 0.47f) {
        // Medium green color
        pixels[index] = 34;
        pixels[index + 1] = 139;
        pixels[index + 2] = 34;
    } else if (val >= 0.1f && val < 0.3f) {
        // Dark green color
        pixels[index] = 0;
        pixels[index + 1] = 128;
        pixels[index + 2] = 0;
    } else if (val >= 0.0f && val < 0.1f) {
        // Very dark green color
        pixels[index] = 0;
        pixels[index + 1] = 100;
        pixels[index + 2] = 0;
    } else if (val >= -0.05f && val < 0.0f) {
        // Light sand color
        pixels[index] = 238;
        pixels[index + 1] = 214;
        pixels[index + 2] = 175;
    } else if (val >= -0.1f && val < -0.05f) {
        // Dark sand color
        pixels[index] = 210;
        pixels[index + 1] = 180;
        pixels[index + 2] = 140;
    } else if (val >= -0.2f && val < -0.1f) {
        // Blue color
        pixels[index] = 0;
        pixels[index + 1] = 0;
        pixels[index + 2] = 255;
    } else if (val >= -0.4f && val < -0.2f) {
        // Blue color
        pixels[index] = 0;
        pixels[index + 1] = 0;
        pixels[index + 2] = 204;
    } else if (val >= -0.7f && val < -0.4f) {
        // Blue color
        pixels[index] = 0;
        pixels[index + 1] = 0;
        pixels[index + 2] = 153;
    } else if (val >= -1.0f && val < -0.7f) {
        // Blue color
        pixels[index] = 0;
        pixels[index + 1] = 0;
        pixels[index + 2] = 102;
    }
    pixels[index + 3] = 255; // Alpha channel
}

void colorScheme7(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.9f) {
        pixels[index] = 0; pixels[index + 1] = 0; pixels[index + 2] = 255;
    }
    else if (val >= 0.8f) {
        pixels[index] = 0; pixels[index + 1] = 55; pixels[index + 2] = 255;
    }
    else if (val >= 0.7f) {
        pixels[index] = 0; pixels[index + 1] = 110; pixels[index + 2] = 255;
    }
    else if (val >= 0.6f) {
        pixels[index] = 0; pixels[index + 1] = 164; pixels[index + 2] = 255;
    }
    else if (val >= 0.5f) {
        pixels[index] = 0; pixels[index + 1] = 219; pixels[index + 2] = 255;
    }
    else if (val >= 0.4f) {
        pixels[index] = 0; pixels[index + 1] = 255; pixels[index + 2] = 218;
    }
    else if (val >= 0.3f) {
        pixels[index] = 0; pixels[index + 1] = 255; pixels[index + 2] = 0;
    }
    else if (val >= 0.2f) {
        pixels[index] = 54; pixels[index + 1] = 255; pixels[index + 2] = 0;
    }
    else if (val >= 0.1f) {
        pixels[index] = 164; pixels[index + 1] = 255; pixels[index + 2] = 0;
    }
    else if (val >= 0.0f) {
        pixels[index] = 219; pixels[index + 1] = 255; pixels[index + 2] = 0;
    }
    else if (val >= -0.1f) {
        pixels[index] = 255; pixels[index + 1] = 237; pixels[index + 2] = 0;
    }
    else if (val >= -0.2f) {
        pixels[index] = 255; pixels[index + 1] = 182; pixels[index + 2] = 0;
    }
    else if (val >= -0.3f) {
        pixels[index] = 255; pixels[index + 1] = 128; pixels[index + 2] = 0;
    }
    else if (val >= -0.4f) {
        pixels[index] = 255; pixels[index + 1] = 73; pixels[index + 2] = 0;
    }
    else if (val >= -0.5f) {
        pixels[index] = 255; pixels[index + 1] = 18; pixels[index + 2] = 0;
    }
    else if (val >= -0.6f) {
        pixels[index] = 255; pixels[index + 1] = 36; pixels[index + 2] = 36;
    }
    else if (val >= -0.7f) {
        pixels[index] = 255; pixels[index + 1] = 91; pixels[index + 2] = 91;
    }
    else if (val >= -0.8f) {
        pixels[index] = 255; pixels[index + 1] = 145; pixels[index + 2] = 145;
    }
    else {
        pixels[index] = 255; pixels[index + 1] = 200; pixels[index + 2] = 200;
    }
    pixels[index + 3] = 255; // Alpha channel
}

void colorScheme8(float val, sf::Uint8* pixels, int index) {
    if (val >= 0.9f) {
        pixels[index] = 255; pixels[index + 1] = 255; pixels[index + 2] = 255; // Белый
    }
    else if (val >= 0.8f) {
        pixels[index] = 224; pixels[index + 1] = 224; pixels[index + 2] = 224; // Очень светло-серый
    }
    else if (val >= 0.7f) {
        pixels[index] = 192; pixels[index + 1] = 192; pixels[index + 2] = 192; // Светло-серый
    }
    else if (val >= 0.6f) {
        pixels[index] = 160; pixels[index + 1] = 160; pixels[index + 2] = 160; // Серый
    }
    else if (val >= 0.5f) {
        pixels[index] = 128; pixels[index + 1] = 128; pixels[index + 2] = 128; // Средне-серый
    }
    else if (val >= 0.4f) {
        pixels[index] = 96; pixels[index + 1] = 96; pixels[index + 2] = 96; // Темно-серый
    }
    else if (val >= 0.3f) {
        pixels[index] = 64; pixels[index + 1] = 64; pixels[index + 2] = 64; // Очень темно-серый
    }
    else if (val >= 0.2f) {
        pixels[index] = 32; pixels[index + 1] = 32; pixels[index + 2] = 32; // Почти черный
    }
    else if (val >= 0.1f) {
        pixels[index] = 16; pixels[index + 1] = 16; pixels[index + 2] = 16; // Очень темно-серый
    }
    else if (val >= 0.0f) {
        pixels[index] = 8; pixels[index + 1] = 8; pixels[index + 2] = 8; // Почти черный
    }
    else if (val >= -0.1f) {
        pixels[index] = 0; pixels[index + 1] = 0; pixels[index + 2] = 0; // Черный
    }
    else if (val >= -0.2f) {
        pixels[index] = 8; pixels[index + 1] = 8; pixels[index + 2] = 8; // Почти черный
    }
    else if (val >= -0.3f) {
        pixels[index] = 16; pixels[index + 1] = 16; pixels[index + 2] = 16; // Очень темно-серый
    }
    else if (val >= -0.4f) {
        pixels[index] = 32; pixels[index + 1] = 32; pixels[index + 2] = 32; // Почти черный
    }
    else if (val >= -0.5f) {
        pixels[index] = 64; pixels[index + 1] = 64; pixels[index + 2] = 64; // Очень темно-серый
    }
    else if (val >= -0.6f) {
        pixels[index] = 96; pixels[index + 1] = 96; pixels[index + 2] = 96; // Темно-серый
    }
    else if (val >= -0.7f) {
        pixels[index] = 128; pixels[index + 1] = 128; pixels[index + 2] = 128; // Средне-серый
    }
    else if (val >= -0.8f) {
        pixels[index] = 160; pixels[index + 1] = 160; pixels[index + 2] = 160; // Серый
    }
    else if (val >= -0.9f) {
        pixels[index] = 192; pixels[index + 1] = 192; pixels[index + 2] = 192; // Светло-серый
    }
    else {
        pixels[index] = 224; pixels[index + 1] = 224; pixels[index + 2] = 224; // Очень светло-серый
    }
    pixels[index + 3] = 255; // Alpha channel
}
