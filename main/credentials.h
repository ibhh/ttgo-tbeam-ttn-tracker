/*

Credentials file

*/

#pragma once

// Only one of these settings must be defined
#define USE_ABP
//#define USE_OTAA

#ifdef USE_ABP

    // LoRaWAN NwkSKey, network session key
    static const u1_t PROGMEM NWKSKEY[16] = { 0x7D, 0x37, 0x54, 0xD2, 0x7A, 0xD7, 0xA7, 0x26, 0x03, 0x86, 0x5A, 0xD5, 0x8E, 0x47, 0xB4, 0xA4 };
    // LoRaWAN AppSKey, application session key
    static const u1_t PROGMEM APPSKEY[16] = { 0xA5, 0x1D, 0xF6, 0x88, 0xD6, 0xE1, 0x7A, 0x09, 0x14, 0x77, 0xD5, 0x01, 0x30, 0xF3, 0x8B, 0x41 };
    // LoRaWAN end-device address (DevAddr)
    // This has to be unique for every node
    static const u4_t DEVADDR = 0x2601112D;

#endif

#ifdef USE_OTAA

    // This EUI must be in little-endian format, so least-significant-byte
    // first. When copying an EUI from ttnctl output, this means to reverse
    // the bytes. For TTN issued EUIs the last bytes should be 0x00, 0x00,
    // 0x00.
    static const u1_t PROGMEM APPEUI[8]  = { 0x17, 0x59, 0x03, 0xD0, 0x7E, 0xD5, 0xB3, 0x70 };

    // This should also be in little endian format, see above.
    // Note: You do not need to set this field, if unset it will be generated automatically based on the device macaddr
    static u1_t DEVEUI[8]  = { 0x01, 0x00, 0x01, 0x00, 0xCA, 0xCA, 0xFA, 0xDE };

    // This key should be in big endian format (or, since it is not really a
    // number but a block of memory, endianness does not really apply). In
    // practice, a key taken from ttnctl can be copied as-is.
    // The key shown here is the semtech default key.
    static const u1_t PROGMEM APPKEY[16] = { 0xA2, 0x09, 0xBB, 0x47, 0x7B, 0x38, 0x60, 0x30, 0x82, 0x64, 0xA3, 0xAC, 0x2F, 0x9B, 0x05, 0x6C };

#endif
