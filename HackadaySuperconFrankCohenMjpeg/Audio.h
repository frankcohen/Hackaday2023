#ifndef _AUDIO_
#define _AUDIO_

#include "config.h"
#include "secrets.h"

#include "AudioGeneratorAAC.h"
#include "AudioOutputI2S.h"
#include "AudioFileSourceSD.h"
#include "AudioSampleAAC.h"
#include <SD.h>

// Depends on https://github.com/earlephilhower/ESP8266Audio

class Audio
{
  public:
    Audio();
    void begin();
    void loop();
    bool test();
    void play( String aname );

  private:
    AudioFileSourceSD *in;
    AudioGeneratorAAC *aac;
    AudioOutputI2S *out;
};

#endif // _AUDIO_
