/*
 Reflections, distributed entertainment device

 Repository is at https://github.com/frankcohen/ReflectionsOS
 Includes board wiring directions, server side components, examples, support

 Licensed under GPL v3 Open Source Software
 (c) Frank Cohen, All rights reserved. fcohen@starlingwatch.com
 Read the license in the license.txt file that comes with this code.

 Depends on https://github.com/earlephilhower/ESP8266Audio
*/

#include "Audio.h"

Audio::Audio(){}

void Audio::begin()
{ 
  pinMode(AudioPower, OUTPUT);      // Turns the speaker amp on
  digitalWrite(AudioPower, HIGH);

  in = new AudioFileSourceSD();
  aac = new AudioGeneratorAAC();
  out = new AudioOutputI2S();
  out -> SetPinout( I2S_bclkPinP, I2S_wclkPinP, I2S_doutPinP);
  out -> SetGain( 0.300 );
}

void Audio::play( String aname )
{
  in -> open( aname.c_str() );
  Serial.println( F( "Playing audio file" ) ); 
  aac->begin(in, out);
}

bool Audio::test()
{
  return true;
}

void Audio::loop()
{
  if (aac->isRunning()) 
  {
    aac->loop();
  }
  
}
