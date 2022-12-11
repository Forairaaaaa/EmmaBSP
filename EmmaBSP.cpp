/**
 * @file EmmaBSP.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "EmmaBSP.h"
#include "esp_flash.h"






/**
 * @brief BSP init 
 * 
 * @param enLcd 
 * @param enEncoder 
 * @param enLedRGB 
 * @param enBuzzer 
 */
void EMMA::Init(bool enLcd, bool enEncoder, bool enLedRGB, bool enBuzzer)
{
    /* LCD init */
    // if (enLcd)
        // lcd.init()
    
    /* Print infomations */
    PrintBoardInfo();

    /* RGB LED init */
    // if (enLedRGB)




}


/**
 * @brief Print board infomations
 * 
 * @param printOnLcd also print on lcd
 */
void EMMA::PrintBoardInfo(bool printOnLcd)
{
    /* Print Logo */
    printf("%s\n", EmmaLogo.c_str());
    printf(" Emma HMI Core Boarad :)\n BSP %s\n", BSP_VERISON);

    /* Print chip and flash information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf(" Get flash size failed");
        return;
    }
    printf(" %u MB %s flash\n", flash_size / (1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
    printf(" Minimum free heap size: %d bytes\n\n", esp_get_minimum_free_heap_size());

    /* Print infos on LCD */
    #if LCD_PRINT_INIT_INFO
    // lcd.setCursor(0, 0);
    // lcd.printf(EmmaLogo.c_str());
    // lcd.printf(" Emma HMI Core Boarad :)\n BSP %s\n", BSP_VERISON);
    // lcd.printf(" %luMB %s flash\n", flash_size / (1024 * 1024),
    //        (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
    // lcd.printf(" Minimum free heap size: %ld bytes\n\n", esp_get_minimum_free_heap_size());
    #endif
}


/**
 * @brief Listen to the cow
 * 
 * @param whatCowSay 
 * @param ANSIcolor 
 * @return string that cow is saying
 */
string EMMA::Cowsay(string whatCowSay, int ANSIcolor)
{
    string ret;

    /* Set corlor */
    if (ANSIcolor != 0)
        ret = "\033[0;" + to_string(ANSIcolor) + "m";
    
    /* Print dialog */
    ret.append(" ");
    ret.append(whatCowSay.length() + 2, '_');
    ret.append("\n< ");
    ret.append(whatCowSay);
    ret.append(" >\n ");
    ret.append(whatCowSay.length() + 2, '-');
    ret.append(Cow);

    /* Reset color */
    if (ANSIcolor != 0)
        ret.append("\033[0m\n");
    else
        ret.append("\n");
    
    return ret;
}