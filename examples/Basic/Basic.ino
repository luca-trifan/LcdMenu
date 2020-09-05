/*
 Basic Menu Navigation

 This sketch demostrates how to get started with the LcdMenu library

 Circuit:
 * Arduino Board
 * Keypad pin 1 to digital pin 9
 * Keypad pin 2 to digital pin 8
 * Keypad pin 3 to digital pin 7
 * Keypad pin 4 to digital pin 6
 * Keypad pin 5 to digital pin 5
 * Keypad pin 6 to digital pin 4
 * Keypad pin 7 to digital pin 3
 * Keypad pin 8 to digital pin 2
 * LCD SLC pin to arduino SLC pin
 * LCD SDA pin to arduino SDA pin

 created 22 July 2020
 by Forntoh Thomas

 This example is in the public domain.

 https://github.com/forntoh/LcdMenu/tree/master/examples/Basic/Basic.ino

*/

#include <Keypad.h>
#include <LcdMenu.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ROWS 2
#define LCD_COLS 16

// Configure keypad keys
char keys[4][4] = {{'1', '2', '3', 'A'},
                   {'4', '5', '6', 'B'},
                   {'7', '8', '9', 'C'},
                   {'*', '0', '#', 'D'}};
// Configure keypad pins
byte colPins[4] = {5, 4, 3, 2};
byte rowPins[4] = {9, 8, 7, 6};

// Define the main menu
extern MenuItem mainMenu[];

// Initialize the main menu items
MenuItem mainMenu[] = {ItemHeader(),
                       MenuItem("Start service"),
                       MenuItem("Connect to WiFi"),
                       MenuItem("Settings"),
                       MenuItem("Blink SOS"),
                       MenuItem("Blink random"),
                       ItemFooter()};
// Construct the LcdMenu
LcdMenu menu(LCD_ROWS, LCD_COLS);

// Setup keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
    // Initialize LcdMenu with the menu items
    menu.setupLcdWithMenu(0x27, mainMenu);
}

void loop() {
    char key = keypad.getKey();
    if (key == NO_KEY) return;

    switch (key) {
        case 'A':
            menu.up();
            break;
        case 'B':
            menu.down();
            break;
        case 'C':
            menu.enter();
            break;
        case 'D':
            menu.back();
            break;
        default:
            break;
    }
}