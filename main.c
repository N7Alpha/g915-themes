//#include <wchar.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define LOG_LEVEL_DEBUG 0

static int log_level = 1;

//#include "LogitechLEDLib.h"
//
// Logitech Gaming LED SDK
//
// Copyright (C) 2011-2014 Logitech. All rights reserved.
// Author: Tiziano Pigliucci
// Email: devtechsupport@logitech.com

#pragma once

#define LOGI_LED_BITMAP_WIDTH 21
#define LOGI_LED_BITMAP_HEIGHT 6
#define LOGI_LED_BITMAP_BYTES_PER_KEY 4

#define LOGI_LED_BITMAP_SIZE (LOGI_LED_BITMAP_WIDTH*LOGI_LED_BITMAP_HEIGHT*LOGI_LED_BITMAP_BYTES_PER_KEY)

#define LOGI_LED_DURATION_INFINITE 0

#define LOGI_DEVICETYPE_MONOCHROME_ORD  0
#define LOGI_DEVICETYPE_RGB_ORD         1
#define LOGI_DEVICETYPE_PERKEY_RGB_ORD  2

#define LOGI_DEVICETYPE_MONOCHROME  (1 << LOGI_DEVICETYPE_MONOCHROME_ORD)
#define LOGI_DEVICETYPE_RGB         (1 << LOGI_DEVICETYPE_RGB_ORD)
#define LOGI_DEVICETYPE_PERKEY_RGB  (1 << LOGI_DEVICETYPE_PERKEY_RGB_ORD)

#define LOGI_DEVICETYPE_ALL (LOGI_DEVICETYPE_MONOCHROME | LOGI_DEVICETYPE_RGB | LOGI_DEVICETYPE_PERKEY_RGB)


typedef enum {
    ESC                     = 0x01,
    F1                      = 0x3b,
    F2                      = 0x3c,
    F3                      = 0x3d,
    F4                      = 0x3e,
    F5                      = 0x3f,
    F6                      = 0x40,
    F7                      = 0x41,
    F8                      = 0x42,
    F9                      = 0x43,
    F10                     = 0x44,
    F11                     = 0x57,
    F12                     = 0x58,
    PRINT_SCREEN            = 0x137,
    SCROLL_LOCK             = 0x46,
    PAUSE_BREAK             = 0x145,
    TILDE                   = 0x29,
    ONE                     = 0x02,
    TWO                     = 0x03,
    THREE                   = 0x04,
    FOUR                    = 0x05,
    FIVE                    = 0x06,
    SIX                     = 0x07,
    SEVEN                   = 0x08,
    EIGHT                   = 0x09,
    NINE                    = 0x0A,
    ZERO                    = 0x0B,
    MINUS                   = 0x0C,
    EQUALS                  = 0x0D,
    BACKSPACE               = 0x0E,
    INSERT                  = 0x152,
    HOME                    = 0x147,
    PAGE_UP                 = 0x149,
    NUM_LOCK                = 0x45,
    NUM_SLASH               = 0x135,
    NUM_ASTERISK            = 0x37,
    NUM_MINUS               = 0x4A,
    TAB                     = 0x0F,
    Q                       = 0x10,
    W                       = 0x11,
    E                       = 0x12,
    R                       = 0x13,
    T                       = 0x14,
    Y                       = 0x15,
    U                       = 0x16,
    I                       = 0x17,
    O                       = 0x18,
    P                       = 0x19,
    OPEN_BRACKET            = 0x1A,
    CLOSE_BRACKET           = 0x1B,
    BACKSLASH               = 0x2B,
    KEYBOARD_DELETE         = 0x153,
    END                     = 0x14F,
    PAGE_DOWN               = 0x151,
    NUM_SEVEN               = 0x47,
    NUM_EIGHT               = 0x48,
    NUM_NINE                = 0x49,
    NUM_PLUS                = 0x4E,
    CAPS_LOCK               = 0x3A,
    A                       = 0x1E,
    S                       = 0x1F,
    D                       = 0x20,
    F                       = 0x21,
    G                       = 0x22,
    H                       = 0x23,
    J                       = 0x24,
    K                       = 0x25,
    L                       = 0x26,
    SEMICOLON               = 0x27,
    APOSTROPHE              = 0x28,
    ENTER                   = 0x1C,
    NUM_FOUR                = 0x4B,
    NUM_FIVE                = 0x4C,
    NUM_SIX                 = 0x4D,
    LEFT_SHIFT              = 0x2A,
    Z                       = 0x2C,
    X                       = 0x2D,
    C                       = 0x2E,
    V                       = 0x2F,
    B                       = 0x30,
    N                       = 0x31,
    M                       = 0x32,
    COMMA                   = 0x33,
    PERIOD                  = 0x34,
    FORWARD_SLASH           = 0x35,
    RIGHT_SHIFT             = 0x36,
    ARROW_UP                = 0x148,
    NUM_ONE                 = 0x4F,
    NUM_TWO                 = 0x50,
    NUM_THREE               = 0x51,
    NUM_ENTER               = 0x11C,
    LEFT_CONTROL            = 0x1D,
    LEFT_WINDOWS            = 0x15B,
    LEFT_ALT                = 0x38,
    SPACE                   = 0x39,
    RIGHT_ALT               = 0x138,
    RIGHT_WINDOWS           = 0x15C,
    APPLICATION_SELECT      = 0x15D,
    RIGHT_CONTROL           = 0x11D,
    ARROW_LEFT              = 0x14B,
    ARROW_DOWN              = 0x150,
    ARROW_RIGHT             = 0x14D,
    NUM_ZERO                = 0x52,
    NUM_PERIOD              = 0x53,
    G_1                     = 0xFFF1,
    G_2                     = 0xFFF2,
    G_3                     = 0xFFF3,
    G_4                     = 0xFFF4,
    G_5                     = 0xFFF5,
    G_6                     = 0xFFF6,
    G_7                     = 0xFFF7,
    G_8                     = 0xFFF8,
    G_9                     = 0xFFF9,
    G_LOGO                  = 0xFFFF1,
    G_BADGE                 = 0xFFFF2,
} KeyName;

typedef enum {
    Keyboard                = 0x0,
    Mouse                   = 0x3,
    Mousemat                = 0x4,
    Headset                 = 0x8,
    Speaker                 = 0xe,
} DeviceType;

typedef bool (*LogiLedInit_t)();
typedef bool (*LogiLedInitWithName_t)(const char name[]);

//bool LogiLedGetSdkVersion(int *majorNum, int *minorNum, int *buildNum);
//bool LogiLedGetConfigOptionNumber(const wchar_t *configPath, double *defaultValue);
//bool LogiLedGetConfigOptionBool(const wchar_t *configPath, bool *defaultValue);
//bool LogiLedGetConfigOptionColor(const wchar_t *configPath, int *defaultRed, int *defaultGreen, int *defaultBlue);
//bool LogiLedGetConfigOptionRect(const wchar_t *configPath, int *defaultX, int *defaultY, int *defaultWidth, int *defaultHeight);
//bool LogiLedGetConfigOptionString(const wchar_t *configPath, wchar_t *defaultValue, int bufferSize);
//bool LogiLedGetConfigOptionKeyInput(const wchar_t *configPath, wchar_t *defaultValue, int bufferSize);
//bool LogiLedGetConfigOptionSelect(const wchar_t *configPath, wchar_t *defaultValue, int *valueSize, const wchar_t *values, int bufferSize);
//bool LogiLedGetConfigOptionRange(const wchar_t *configPath, int *defaultValue, int min, int max);
//bool LogiLedSetConfigOptionLabel(const wchar_t *configPath, wchar_t *label);

//Generic functions => Apply to any device type.
typedef bool (*LogiLedSetTargetDevice_t)(int targetDevice);
typedef bool (*LogiLedSaveCurrentLighting_t)();
typedef bool (*LogiLedSetLighting_t)(int redPercentage, int greenPercentage, int bluePercentage);
typedef bool (*LogiLedRestoreLighting_t)();
typedef bool (*LogiLedFlashLighting_t)(int redPercentage, int greenPercentage, int bluePercentage, int milliSecondsDuration, int milliSecondsInterval);
typedef bool (*LogiLedPulseLighting_t)(int redPercentage, int greenPercentage, int bluePercentage, int milliSecondsDuration, int milliSecondsInterval);
typedef bool (*LogiLedStopEffects_t)();

//Per-key functions => only apply to LOGI_DEVICETYPE_PERKEY_RGB devices.
typedef bool (*LogiLedSetLightingFromBitmap_t)(unsigned char bitmap[]);
typedef bool (*LogiLedSetLightingForKeyWithScanCode_t)(int keyCode, int redPercentage, int greenPercentage, int bluePercentage);
typedef bool (*LogiLedSetLightingForKeyWithHidCode_t)(int keyCode, int redPercentage, int greenPercentage, int bluePercentage);
typedef bool (*LogiLedSetLightingForKeyWithQuartzCode_t)(int keyCode, int redPercentage, int greenPercentage, int bluePercentage);
typedef bool (*LogiLedSetLightingForKeyWithKeyName_t)(KeyName keyName, int redPercentage, int greenPercentage, int bluePercentage);
typedef bool (*LogiLedSaveLightingForKey_t)(KeyName keyName);
typedef bool (*LogiLedRestoreLightingForKey_t)(KeyName keyName);
typedef bool (*LogiLedExcludeKeysFromBitmap_t)(KeyName *keyList, int listCount);

//Per-key effects => only apply to LOGI_DEVICETYPE_PERKEY_RGB devices.
bool LogiLedFlashSingleKey(KeyName keyName, int redPercentage, int greenPercentage, int bluePercentage, int msDuration, int msInterval);
bool LogiLedPulseSingleKey(KeyName keyName, int startRedPercentage, int startGreenPercentage, int startBluePercentage, int finishRedPercentage, int finishGreenPercentage, int finishBluePercentage, int msDuration, bool isInfinite);
bool LogiLedStopEffectsOnKey(KeyName keyName);

//Zonal functions => only apply to devices with zones.
bool LogiLedSetLightingForTargetZone(DeviceType deviceType, int zone, int redPercentage, int greenPercentage, int bluePercentage);

typedef void (*LogiLedShutdown_t)();

//#include "_noise.h"
#if defined(_MSC_VER)
#define inline _inline
#define M_1_PI 0.31830988618379067154
#endif

const float GRAD3[][3] = {
    {1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0}, 
    {1,0,1},{-1,0,1},{1,0,-1},{-1,0,-1}, 
    {0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1},
    {1,0,-1},{-1,0,-1},{0,-1,1},{0,1,1}};

const float GRAD4[][4] = {
    {0,1,1,1}, {0,1,1,-1}, {0,1,-1,1}, {0,1,-1,-1},
    {0,-1,1,1}, {0,-1,1,-1}, {0,-1,-1,1}, {0,-1,-1,-1},
    {1,0,1,1}, {1,0,1,-1}, {1,0,-1,1}, {1,0,-1,-1},
    {-1,0,1,1}, {-1,0,1,-1}, {-1,0,-1,1}, {-1,0,-1,-1},
    {1,1,0,1}, {1,1,0,-1}, {1,-1,0,1}, {1,-1,0,-1},
    {-1,1,0,1}, {-1,1,0,-1}, {-1,-1,0,1}, {-1,-1,0,-1},
    {1,1,1,0}, {1,1,-1,0}, {1,-1,1,0}, {1,-1,-1,0},
    {-1,1,1,0}, {-1,1,-1,0}, {-1,-1,1,0}, {-1,-1,-1,0}};

// At the possible cost of unaligned access, we use char instead of
// int here to try to ensure that this table fits in L1 cache
const unsigned char PERM[] = {
  151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140,
  36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148, 247, 120,
  234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
  88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71,
  134, 139, 48, 27, 166, 77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133,
  230, 220, 105, 92, 41, 55, 46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161,
  1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196, 135, 130,
  116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250,
  124, 123, 5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227,
  47, 16, 58, 17, 182, 189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44,
  154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98,
  108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34,
  242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14,
  239, 107, 49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121,
  50, 45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243,
  141, 128, 195, 78, 66, 215, 61, 156, 180, 151, 160, 137, 91, 90, 15, 131,
  13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37,
  240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252,
  219, 203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125,
  136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158,
  231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245,
  40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187,
  208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 198,
  173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118, 126,
  255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42, 223,
  183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167,
  43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185,
  112, 104, 218, 246, 97, 228, 251, 34, 242, 193, 238, 210, 144, 12, 191, 179,
  162, 241, 81, 51, 145, 235, 249, 14, 239, 107, 49, 192, 214, 31, 181, 199,
  106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236,
  205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156,
  180};

const unsigned char SIMPLEX[][4] = {
    {0,1,2,3},{0,1,3,2},{0,0,0,0},{0,2,3,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {1,2,3,0},{0,2,1,3},{0,0,0,0},{0,3,1,2},{0,3,2,1},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{1,3,2,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{1,2,0,3},{0,0,0,0},{1,3,0,2},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{2,3,0,1},{2,3,1,0},{1,0,2,3},{1,0,3,2},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{2,0,3,1},{0,0,0,0},{2,1,3,0},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,0,1,3},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{3,0,1,2},{3,0,2,1},{0,0,0,0},{3,1,2,0}, 
    {2,1,0,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,1,0,2},{0,0,0,0},{3,2,0,1},
    {3,2,1,0}};

#define fastfloor(n) (int)(n) - (((n) < 0.0f) & ((n) != (int)(n)))

// Fast sine/cosine functions from
// http://devmaster.net/forums/topic/4648-fast-and-accurate-sinecosine/page__st__80
// Note the input to these functions is not radians
// instead x = [0, 2] for r = [0, 2*PI]

static inline float fast_sin(float x) {
    // Convert the input value to a range of -1 to 1
    // x = x * (1.0f / PI);

    // Wrap around
    volatile float z = (x + 25165824.0f);
    x = x - (z - 25165824.0f);

    #if LOW_SINE_PRECISION
        return 4.0f * (x - x * fabsf(x));
    #else
    {
        float y = x - x * fabsf(x);
        const float Q = 3.1f;
        const float P = 3.6f;
        return y * (Q + P * fabsf(y));
    }
    #endif
}

static inline float fast_cos(float x) {
    return fast_sin(x + 0.5f);
}

#pragma warning(push)
#pragma warning(disable: 4244)
//#include "_perlin.c"
#define lerp(t, a, b) ((a) + (t) * ((b) - (a)))

static inline float
grad2(const int hash, const float x, const float y) {
    const int h = hash & 15;
    return x * GRAD3[h][0] + y * GRAD3[h][1];
}

static float noise2(float x, float y, const float repeatx, const float repeaty, const int base) {
    float fx, fy;
    int A, AA, AB, B, BA, BB;
    int i = (int)floorf(fmodf(x, repeatx));
    int j = (int)floorf(fmodf(y, repeaty));
    int ii = (int)fmodf(i + 1, repeatx);
    int jj = (int)fmodf(j + 1, repeaty);
    i = (i & 255) + base;
    j = (j & 255) + base;
    ii = (ii & 255) + base;
    jj = (jj & 255) + base;

    x -= floorf(x); y -= floorf(y);
    fx = x*x*x * (x * (x * 6 - 15) + 10);
    fy = y*y*y * (y * (y * 6 - 15) + 10);

    A = PERM[i];
    AA = PERM[A + j];
    AB = PERM[A + jj];
    B = PERM[ii];
    BA = PERM[B + j];
    BB = PERM[B + jj];
        
    return lerp(fy, lerp(fx, grad2(PERM[AA], x, y),
                             grad2(PERM[BA], x - 1, y)),
                    lerp(fx, grad2(PERM[AB], x, y - 1),
                             grad2(PERM[BB], x - 1, y - 1)));
}

// Default values for the python implementation
static const int pnoise2_octaves_default = 1;
static const float pnoise2_persistence_default = 0.5f;
static const float pnoise2_lacunarity_default = 2.0f;
static const float pnoise2_repeatx_default = 1024.0f;
static const float pnoise2_repeaty_default = 1024.0f;
static const int pnoise2_base_default = 0;

static float pnoise2(float x, float y, int octaves, float persistence, float lacunarity, float repeatx, float repeaty, int base) {
    assert(octaves > 0);

    if (octaves == 1) {
        return noise2(x, y, repeatx, repeaty, base);
    } else {
        float freq = 1.0f;
        float amp = 1.0f;
        float max = 0.0f;
        float total = 0.0f;

        for (int i = 0; i < octaves; i++) {
            total += noise2(x * freq, y * freq, repeatx * freq, repeaty * freq, base) * amp;
            max += amp;
            freq *= lacunarity;
            amp *= persistence;
        }
        return total / max;
    }
}

#pragma warning(pop)

#define ENUM_FUNCTIONS(F) \
    F(LogiLedInit) \
    F(LogiLedInitWithName) \
    F(LogiLedSetTargetDevice) \
    F(LogiLedSaveCurrentLighting) \
    F(LogiLedSetLighting) \
    F(LogiLedRestoreLighting) \
    F(LogiLedFlashLighting) \
    F(LogiLedPulseLighting) \
    F(LogiLedStopEffects) \
    F(LogiLedSetLightingFromBitmap) \
    F(LogiLedSetLightingForKeyWithScanCode) \
    F(LogiLedSetLightingForKeyWithHidCode) \
    F(LogiLedSetLightingForKeyWithQuartzCode) \
    F(LogiLedSetLightingForKeyWithKeyName) \
    F(LogiLedSaveLightingForKey) \
    F(LogiLedRestoreLightingForKey) \
    F(LogiLedExcludeKeysFromBitmap) \
    F(LogiLedShutdown) \

#define DECLARE_FUNCTION_POINTER(name) \
    static name##_t name;

ENUM_FUNCTIONS(DECLARE_FUNCTION_POINTER)

// The voids are used for correctly calculating which pixel a key is at in the bitmap
// The alternative is using the per-key api logitech gives or just storing the pixel coordinates in this struct
typedef struct key_data { 
    KeyName code;
    int x;
    int y;
} key_data_t;

#define KEY_VOID 0xDEAD
static key_data_t keys[] = {
    {ESC, 49, 97},
    {F1, 148, 97},
    {F2, 206, 97},
    {F3, 264, 97},
    {F4, 322, 97},
    {F5, 420, 97},
    {F6, 479, 97},
    {F7, 538, 97},
    {F8, 596, 97},
    {F9, 694, 97},
    {F10, 753, 97},
    {F11, 812, 97},
    {F12, 870, 97},
    {PRINT_SCREEN, 950, 97},
    {SCROLL_LOCK, 1009, 97},
    {PAUSE_BREAK, 1067, 97},
    {TILDE, 49, 171},
    {ONE, 109, 171},
    {TWO, 167, 171},
    {THREE, 226, 171},
    {FOUR, 285, 171},
    {FIVE, 343, 171},
    {SIX, 402, 171},
    {SEVEN, 461, 171},
    {EIGHT, 520, 171},
    {NINE, 578, 171},
    {ZERO, 637, 171},
    {MINUS, 696, 171},
    {EQUALS, 754, 171},
    {BACKSPACE, 843, 171},
    {INSERT, 950, 171},
    {HOME, 1009, 171},
    {PAGE_UP, 1067, 171},
    {NUM_LOCK, 1067, 97},
    {NUM_SLASH, -1, 171},
    {NUM_ASTERISK, 950, 97},
    {NUM_MINUS, -1, 171},
    {TAB, 64, 230},
    {Q, 138, 230},
    {W, 197, 230},
    {E, 255, 230},
    {R, 313, 230},
    {T, 373, 230},
    {Y, 432, 230},
    {U, 490, 230},
    {I, 549, 230},
    {O, 607, 230},
    {P, 666, 230},
    {OPEN_BRACKET, 725, 230},
    {CLOSE_BRACKET, 784, 230},
    {BACKSLASH, 857, 230},
    {KEYBOARD_DELETE, 950, 230},
    {END, 1009, 230},
    {PAGE_DOWN, 1068, 230},
    {NUM_SEVEN, 1009, 171},
    {NUM_EIGHT, 1009, 347},
    {NUM_NINE, 1067, 171},
    {NUM_PLUS, -1, 230},
    {CAPS_LOCK, 65, 288},
    {A, 153, 288},
    {S, 212, 288},
    {D, 270, 288},
    {F, 328, 288},
    {G, 387, 288},
    {H, 446, 288},
    {J, 505, 288},
    {K, 562, 288},
    {L, 621, 288},
    {SEMICOLON, 681, 288},
    {APOSTROPHE, 740, 288},
    {KEY_VOID, -1, -1},
    {ENTER, 835, 288},
    {NUM_FOUR, 949, 406},
    {NUM_FIVE, -1, 288},
    {NUM_SIX, 1069, 406},
    {LEFT_SHIFT, 86, 347},
    {KEY_VOID, -1, -1},
    {Z, 182, 347},
    {X, 240, 347},
    {C, 299, 347},
    {V, 358, 347},
    {B, 416, 347},
    {N, 475, 347},
    {M, 534, 347},
    {COMMA, 592, 347},
    {PERIOD, 651, 347},
    {FORWARD_SLASH, 710, 347},
    {KEY_VOID, -1, -1},
    {RIGHT_SHIFT, 821, 347},
    {KEY_VOID, -1, -1},
    {ARROW_UP, 1009, 347},
    {NUM_ONE, 1009, 230},
    {NUM_TWO, 1009, 406},
    {NUM_THREE, 1068, 230},
    {NUM_ENTER, -1, 347},
    {LEFT_CONTROL, 64, 406},
    {LEFT_WINDOWS, 145, 406},
    {LEFT_ALT, 219, 406},
    {KEY_VOID, -1, -1},
    {KEY_VOID, -1, -1},
    {SPACE, 424, 406},
    {KEY_VOID, -1, -1},
    {KEY_VOID, -1, -1},
    {KEY_VOID, -1, -1},
    {KEY_VOID, -1, -1},
    {KEY_VOID, -1, -1},
    {RIGHT_ALT, 630, 406},
    {RIGHT_WINDOWS, 703, 406},
    {APPLICATION_SELECT, 776, 406},
    {RIGHT_CONTROL, 857, 406},
    {ARROW_LEFT, 949, 406},
    {ARROW_DOWN, 1009, 406},
    {ARROW_RIGHT, 1069, 406},
    {NUM_ZERO, 950, 171},
    {NUM_PERIOD, 950, 230},
    {G_1, -1, -1},
    {G_2, -1, -1},
    {G_3, -1, -1},
    {G_4, -1, -1},
    {G_5, -1, -1},
    {G_6, -1, -1},
    {G_7, -1, -1},
    {G_8, -1, -1},
    {G_9, -1, -1},
    {G_LOGO, -1, -1},
    {G_BADGE, -1, -1}
};

static key_data_t* locate_key(KeyName key_code) {
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        if (keys[i].code == key_code) {
            return &keys[i];
        }
    }

    return NULL;
}

static void key_assign_coordinate(KeyName dst_key_code, KeyName src_key_code_b) {
    key_data_t* dst_key = locate_key(dst_key_code);
    key_data_t* src_key = locate_key(src_key_code_b);

    assert(dst_key != NULL);
    assert(src_key != NULL);

    dst_key->x = src_key->x;
    dst_key->y = src_key->y;
}

static int key_get_index(KeyName key_code) {
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        if (keys[i].code == key_code) {
            return i;
        }
    }

    assert(0); return 0;
}

// ctrl-c handling
#include <signal.h>
volatile sig_atomic_t keepRunning = 1;

static BOOL WINAPI ConsoleHandler(DWORD signal) {
    if (signal == CTRL_C_EVENT) {
        keepRunning = 0;
        return TRUE;
    }

    return FALSE;
}

static void generate_perlin_noise(float scale, float elapsed_seconds, float speed_keys_per_second, float (*noise_intensity)[LOGI_LED_BITMAP_WIDTH]) {
    for (int y = 0; y < LOGI_LED_BITMAP_HEIGHT; y++) {
        for (int x = 0; x < LOGI_LED_BITMAP_WIDTH; x++) {
            float noise_val = pnoise2(x * scale, y * scale + speed_keys_per_second * elapsed_seconds, pnoise2_octaves_default, pnoise2_persistence_default, 
                pnoise2_lacunarity_default, (float) LOGI_LED_BITMAP_WIDTH, (float) LOGI_LED_BITMAP_HEIGHT, pnoise2_base_default);
            noise_intensity[y][x] = (72 + noise_val * 128) / 255.0f;
        }
    }
}

static void combine_effects_and_generate_buffer(
    float (*noise_effect)[LOGI_LED_BITMAP_WIDTH],
    float (*rain_effect)[LOGI_LED_BITMAP_WIDTH],
    unsigned char (*bgra_bitmap)[LOGI_LED_BITMAP_WIDTH][LOGI_LED_BITMAP_BYTES_PER_KEY]
) {
    for (int y = 0; y < LOGI_LED_BITMAP_HEIGHT; ++y) {
        for (int x = 0; x < LOGI_LED_BITMAP_WIDTH; ++x) {
            // Combine and clip effects
            float intensity = noise_effect[y][x] + rain_effect[y][x];
            if (intensity > 1.0f) intensity = 1.0f;
            if (intensity < 0.0f) intensity = 0.0f;

            // Convert to BGRA - using green channel for intensity
            int green_intensity = (int)(intensity * 255);
            bgra_bitmap[y][x][0] = 0;                   // Blue
            bgra_bitmap[y][x][1] = green_intensity;     // Green
            bgra_bitmap[y][x][2] = 0;                   // Red
            bgra_bitmap[y][x][3] = 255;                 // Alpha
        }
    }
}

static int _row_offsets[LOGI_LED_BITMAP_HEIGHT];

static void bitmap_coordinate_for_scan_code(int key_code, int *x_out, int *y_out) {
    int x, y;

    int index = key_get_index(key_code);

    for (y = 0; y < LOGI_LED_BITMAP_HEIGHT-1; y++) {
        if (index < _row_offsets[y+1]) {
            break;
        }
    }

    x = index - _row_offsets[y];

    assert(x < LOGI_LED_BITMAP_WIDTH);

    *x_out = x;
    *y_out = y;
}

// Puts the key in a space where 1-unit is 1-key give or take
static void key_keyboard_space_coordinate(KeyName key_code, float *x, float *y) {
    key_data_t key_origin = keys[key_get_index(ESC)];
    key_data_t key_extent = keys[key_get_index(ARROW_RIGHT)];

    int index = key_get_index(key_code);
    key_data_t key = keys[index];

    *x = LOGI_LED_BITMAP_WIDTH  * (key.x - key_origin.x) / (float) key_extent.x;
    *y = LOGI_LED_BITMAP_HEIGHT * (key.y - key_origin.y) / (float) key_extent.y;
}

#define DIGITAL_RAIN_KEYS_PER_SECOND 0.3f
#define DIGITAL_RAIN_RAINDROPS_MAX 32

static struct {
    float start_x;
    float start_y;
    float start_seconds;
} raindrops[DIGITAL_RAIN_RAINDROPS_MAX] = {0};

static int raindrops_next = 0;

float digital_rain_raindrop_speed_keys_per_second = 4;
float jkr_dr_raindrop_width_parameter = -2.5f;

static void generate_rain(float time_seconds, float (*rain_intensity)[LOGI_LED_BITMAP_WIDTH]) {

    // Calculate the illumination of each key for all raindrops
    for (int k = 0; k < sizeof(keys) / sizeof(keys[0]); k++) {
        if (keys[k].code == KEY_VOID) continue;
        if (keys[k].code == G_1) break; // @todo My logic is just broken and I can't handle this

        int x, y;
        bitmap_coordinate_for_scan_code(keys[k].code, &x, &y);

        float kx, ky;
        key_keyboard_space_coordinate(keys[k].code, &kx, &ky);

        for (int r = 0; r < DIGITAL_RAIN_RAINDROPS_MAX; r++) {
            float ry = raindrops[r].start_y + digital_rain_raindrop_speed_keys_per_second * (time_seconds - raindrops[r].start_seconds);
            float rx = raindrops[r].start_x;

            float d = hypotf(kx - rx, ky - ry);
            rain_intensity[y][x] += expf(jkr_dr_raindrop_width_parameter * d);
        }
    }
}

// This callback basically acts like a keylogger. It get's all keyboard events from the OS no matter what
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) lParam;
        switch (wParam) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
                // Handle key down event
                if (log_level <= LOG_LEVEL_DEBUG) {
                    printf("Key down: %lu\n", p->scanCode);
                }

                key_keyboard_space_coordinate(p->scanCode, 
                                              &raindrops[raindrops_next].start_x,
                                              &raindrops[raindrops_next].start_y);

                raindrops[raindrops_next].start_seconds = GetTickCount64() / 1000.0f;

                if (log_level <= LOG_LEVEL_DEBUG) {
                    printf("Raindrop at %f, %f\n", raindrops[raindrops_next].start_x, raindrops[raindrops_next].start_y);
                    printf("Time: %f\n", raindrops[raindrops_next].start_seconds);
                    fflush(stdout);
                }

                raindrops_next = (raindrops_next + 1) % DIGITAL_RAIN_RAINDROPS_MAX;


                break;
            case WM_KEYUP:
            case WM_SYSKEYUP:
                // Handle key up event
                if (log_level <= LOG_LEVEL_DEBUG) {
                    printf("Key up: %lu\n", p->scanCode);
                }

                break;
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}


int main() {
    bool g915_tkl = true;

    if (g915_tkl) {
        // The arrow keys scan out as numpad keys for some reason on my g915 TKL. That seems correct
        //  if num lock is off, but why does Logitech not just use the 'correct' scan code to begin with?
        key_assign_coordinate(NUM_EIGHT, ARROW_UP);
        key_assign_coordinate(NUM_TWO, ARROW_DOWN);
        key_assign_coordinate(NUM_FOUR, ARROW_LEFT);
        key_assign_coordinate(NUM_SIX, ARROW_RIGHT);
        key_assign_coordinate(NUM_SEVEN, HOME);
        key_assign_coordinate(NUM_ONE, END);
        key_assign_coordinate(NUM_NINE, PAGE_UP);
        key_assign_coordinate(NUM_THREE, PAGE_DOWN);
        key_assign_coordinate(NUM_ZERO, INSERT);
        key_assign_coordinate(NUM_PERIOD, KEYBOARD_DELETE);
        key_assign_coordinate(NUM_ASTERISK, PRINT_SCREEN);

        // This one is a mystery to me
        key_assign_coordinate(NUM_LOCK, PAUSE_BREAK);
    }

    int *ptr = _row_offsets;
    *(ptr++) = (int) (locate_key(ESC) - keys);
    *(ptr++) = (int) (locate_key(TILDE) - keys);
    *(ptr++) = (int) (locate_key(TAB) - keys);
    *(ptr++) = (int) (locate_key(CAPS_LOCK) - keys);
    *(ptr++) = (int) (locate_key(LEFT_SHIFT) - keys);
    *(ptr++) = (int) (locate_key(LEFT_CONTROL) - keys);

    // Set the console control handler
    SetConsoleCtrlHandler(ConsoleHandler, TRUE);

    const char *library_name = "C:\\Program Files\\LGHUB\\sdks\\sdk_legacy_led_x64.dll";
    HMODULE hDll = LoadLibrary(library_name);

    // Check if the DLL is loaded
    if (!hDll) {
        MessageBox(NULL, 
                   "Couldn't find dll at 'C:\\Program Files\\LGHUB\\sdks\\sdk_legacfy_led_x64.dll' you probably need to install Logitech G Hub", 
                   "DLL Load Error", 
                   MB_ICONERROR | MB_OK);
        return 1;
    }

    // Get function pointers
    #define GET_FUNCTION_POINTER(name) \
        name = (name##_t)GetProcAddress(hDll, #name); \
        if (name == NULL) { \
            fprintf(stderr, "Could not locate function '" #name "' in the DLL!\n"); \
            FreeLibrary(hDll); \
            return 1; \
        }

    ENUM_FUNCTIONS(GET_FUNCTION_POINTER)

    // Init Logitech LED SDK
    if (LogiLedInit()) {
        printf("LogiLed initialized successfully.\n");
    } else {
        fprintf(stderr, "LogiLed initialization failed.\n");
        FreeLibrary(hDll);
        return -1;
    }

    Sleep(500); // Wait for the SDK to finish initializing

    // Set the keyboard hook
    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);

    int frames_per_second = 30;
    while (keepRunning) {
        // Boilerplate so that we can get input. `GetMessage()` doesn't work because I think Logitech's SDK unloads
        // our keyboard hook before we get the ctrl-c message ourselves... that's what I speculate at least
        MSG msg;
        if (MsgWaitForMultipleObjects(0, NULL, FALSE, 1000/frames_per_second, QS_ALLINPUT) == WAIT_OBJECT_0) {
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        float elapsed_seconds = GetTickCount64() / 1000.0f;

        float scale = 5;

        float noise_intensity[LOGI_LED_BITMAP_HEIGHT][LOGI_LED_BITMAP_WIDTH];
        generate_perlin_noise(scale, elapsed_seconds, DIGITAL_RAIN_KEYS_PER_SECOND, noise_intensity);

        float rain_intensity[LOGI_LED_BITMAP_HEIGHT][LOGI_LED_BITMAP_WIDTH] = {0};
        generate_rain(elapsed_seconds, rain_intensity);

        unsigned char bgra_bitmap[LOGI_LED_BITMAP_HEIGHT][LOGI_LED_BITMAP_WIDTH][LOGI_LED_BITMAP_BYTES_PER_KEY] = {0};
        combine_effects_and_generate_buffer(noise_intensity, rain_intensity, bgra_bitmap);

        LogiLedSetLightingFromBitmap((unsigned char *) bgra_bitmap);
    }

    printf("Cleaning up...\n");
    fflush(stdout);
    UnhookWindowsHookEx(hhkLowLevelKybd);
    LogiLedShutdown();

    // Free the DLL module
    FreeLibrary(hDll);
    return 0;
}
