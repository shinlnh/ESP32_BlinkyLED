#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
void app_main(void)
{
	gpio_config_t GPIO_config = {};
	GPIO_config.pin_bit_mask = (1<<18);
	GPIO_config.mode = GPIO_MODE_OUTPUT;
	GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;
	GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	GPIO_config.intr_type = GPIO_INTR_DISABLE;
	
	gpio_config(&GPIO_config);
	while(1)
	{
		gpio_set_level(18,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        gpio_set_level(18,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
		
	}
}
