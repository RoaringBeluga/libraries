#include <Arduino.h>
#include <Wire.h>

#include "EEPROM.h"

EEPROM myPROM(); //Assume default I2C address (0x57)
// EEPROM myPROM (MY_PROM_ADDRESS); // Set I2C address to MY_PROM_ADDRESS

void setup()
{
  Serial.begin(9600);
  // Write and read 1 byte...
  Serial.print("Writing 0x23 to the EEPROM at the address 0x00...");
  myPROM.write(0x00, (uint8_t) 0x23); // Typecast to 8-bit integer...
  Serial.println("done.");
  Serial.print("Reading from EEPROM address 0x00...");
  uint8_t myByte = EEPROM.readB(0x00); // Read 1 byte from 0x00...
  Serial.print("done. Read value: ");
  Serial.println(myByte, HEX);
  // Write and read 1 word (2 bytes)...
  Serial.print("Writing 0x0023 to the EEPROM at the address 0x00...");
  myPROM.write(0x00, (int) 0x23); // Typecast to 16-bit integer...
  Serial.println("done.");
  Serial.print("Reading from EEPROM address 0x00...");
  uint16_t myWord = EEPROM.readW(0x00); // read a word from 0x00
  Serial.print("done. Read value: ");
  Serial.println(myWord, HEX);
  // Write and read 1 byte from out-of-bounds address...
  Serial.print("Writing 0x23 to the EEPROM at the address 4099...");
  myPROM.write(4099, (uint8_t) 0x42);
  Serial.println("done.");
  Serial.print("Reading from EEPROM address 4099...");
  myByte = EEPROM.readB(4099);
  Serial.print("done. Read value: ");
  Serial.println(myByte, HEX);
  // ... and writing an integer in a circular buffer.
  // Two bytes shoul be at the addresses 0 and 4095...
  Serial.print("Writing 0x2332 to the EEPROM at the address 4095...");
  myPROM.write(4095, 0x2332);
  Serial.println("done.");
  Serial.print("Reading from EEPROM address 0x00...");
  uint16_t myWord = EEPROM.readW(4095);
  Serial.print("done. Read value: ");
  Serial.println(myWord, HEX);
  Serial.print("    Byte at the address 0000: ");
  Serial.print(readB(0x00), HEX);
  Serial.print(" and byte at the address 4095: ");
  Serial.println(readB(4095), HEX);
  Serial.println("Finished!");
}

void loop()
{
  // Nothing left to do in the loop...
}
