#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_nvic.h"
#include "sl_board_init.h"
#include "sl_device_init_dcdc.h"
#include "sl_device_init_hfxo.h"
#include "sl_device_init_lfxo.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "btl_interface.h"
#include "sl_board_control.h"
#include "sl_sleeptimer.h"
#include "sl_emlib_gpio_simple_init.h"
#include "gpiointerrupt.h"
#include "sl_iostream_stdlib_config.h"
#include "sl_iostream_init_usart_instances.h"
#include "sl_pwm_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_cli_instances.h"
#include "cpu.h"
#include "cmsis_os2.h"
#include "sl_iostream_init_instances.h"

void sl_platform_init(void)
{
  CHIP_Init();
  sl_device_init_nvic();
  sl_board_preinit();
  sl_device_init_dcdc();
  sl_device_init_hfxo();
  sl_device_init_lfxo();
  sl_device_init_clocks();
  sl_device_init_emu();
  sl_board_init();
  bootloader_init();
  CPU_Init();
  osKernelInitialize();
}

void sl_kernel_start(void)
{
  osKernelStart();
}

void sl_driver_init(void)
{
  sl_emlib_gpio_simple_init();
  GPIOINT_Init();
  sl_pwm_init_instances();
  sl_simple_led_init_instances();
}

void sl_service_init(void)
{
  sl_board_configure_vcom();
  sl_sleeptimer_init();
  sl_iostream_stdlib_disable_buffering();
  sl_iostream_init_instances();
  sl_cli_instances_init();
}

void sl_stack_init(void)
{
}

void sl_internal_app_init(void)
{
}

void sl_iostream_init_instances(void)
{
  sl_iostream_usart_init_instances();
}

