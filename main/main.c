/*
Chase Bailey
1/19/26
This code turns the button on when it is pressed and turns it off when it is pressed again.
*/


#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_10     // Choose your LED pin
#define BUTTON_PIN GPIO_NUM_9     // Choose your button pin

void app_main(void) {
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_pullup_dis(LED_PIN);
    gpio_pulldown_dis(LED_PIN);
    gpio_intr_disable(LED_PIN);
    gpio_reset_pin(BUTTON_PIN);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_pulldown_en(BUTTON_PIN);
    // TO-DO: Configure LED output
    // TO-DO: Configure Button input
    bool isOn = false;
    bool isPressed = false;
    while (1) {
    // TO-DO: Implement LED toggle and button logic here
        if(!isOn && gpio_get_level(BUTTON_PIN) && !isPressed){
            gpio_set_level(LED_PIN, 1);
            isOn = true;
            isPressed = true;
        }
        else if(gpio_get_level(BUTTON_PIN) && !isPressed){
            gpio_set_level(LED_PIN, 0);
            isOn = false;
            isPressed = true;
        }
        else{
            isPressed = false;
        }
        vTaskDelay(25 / portTICK_PERIOD_MS); //Use appropriate loop delays
    }
}