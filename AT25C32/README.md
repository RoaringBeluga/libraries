# AT25C32 library

This library works with AT25C32 IIC EEPROM chips as found on cheap DS3201 RTC modules. The chip provides 32 kbit of EEPROM (4096 bytes) of storage.

This storage is organized as a ring buffer, so if you try to read or store data above the upper address limit it will wrap to the beginning. For example, reading from address 4096 will actually read from address 0 and so on.

Licensed under CC BY-SA 4.0
