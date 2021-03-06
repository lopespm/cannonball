#pragma once

//#include "globals.hpp"

#ifdef COMPILE_SOUND_CODE
#ifdef SDL2
#include "sdl2/audio.hpp"
#else
#include "sdl/audio.hpp"
#endif
#endif

#include "externalinput.hpp"

class ExternalInterface
{
public:
    ExternalInterface();
    ~ExternalInterface();

    void init();
    void reset();
    void close();
    void tick(ExternalInput external_input);

    uint32_t* get_pixels_rgb();
    uint32_t* get_pixels_greyscale();
    int get_screen_width();
    int get_screen_height();
    uint32_t get_score();
    uint32_t get_speed();
    uint32_t num_wheels_off_road();
    bool is_crashed();
    bool is_game_over();
};

// Expose these methods for posterior usage inside python
// Since ctypes can only talk to C functions, you need to provide those declaring them as extern "C"
extern "C" {
    ExternalInterface* ExternalInterface_new(){ return new ExternalInterface(); }
    void ExternalInterface_init(ExternalInterface* externalInterface){ externalInterface->init(); }
    void ExternalInterface_reset(ExternalInterface* externalInterface){ externalInterface->reset(); }
    void ExternalInterface_close(ExternalInterface* externalInterface){ externalInterface->close(); }
    void ExternalInterface_tick(ExternalInterface* externalInterface, ExternalInput externalInput){ externalInterface->tick(externalInput); }
    uint32_t* ExternalInterface_getPixelsRGB(ExternalInterface* externalInterface){ return externalInterface->get_pixels_rgb(); }
    uint32_t* ExternalInterface_getPixelsGreyscale(ExternalInterface* externalInterface){ return externalInterface->get_pixels_greyscale(); }
    int ExternalInterface_getScreenWidth(ExternalInterface* externalInterface){ return externalInterface->get_screen_width(); }
    int ExternalInterface_getScreenHeight(ExternalInterface* externalInterface){ return externalInterface->get_screen_height(); }
    uint32_t ExternalInterface_getScore(ExternalInterface* externalInterface){ return externalInterface->get_score(); }
    uint32_t ExternalInterface_getSpeed(ExternalInterface* externalInterface){ return externalInterface->get_speed(); }
    uint32_t ExternalInterface_numWheelsOffRoad(ExternalInterface* externalInterface){ return externalInterface->num_wheels_off_road(); }
    bool ExternalInterface_isCrashed(ExternalInterface* externalInterface){ return externalInterface->is_crashed(); }
    bool ExternalInterface_isGameOver(ExternalInterface* externalInterface){ return externalInterface->is_game_over(); }
}

extern ExternalInterface external_interface;