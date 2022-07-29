# STM32_USB_CDC_Libusb_linux_simple_code

* Using STM32H723 Nucleo Board
* STM32H723 USB CDC Driver generated from STM32CubeMX
* Ubuntu 20.04.4 Environment
* sudo apt-get install libusb-1.0-0-dev
* gcc stm32_usb_cdc_libusb_sample.c -o stm32_usb_cdc_libusb_sample -I/usr/include/libusb-1.0 -L/usr/lib -lusb-1.0
* ./stm32_usb_cdc_libusb_sample
* Press the blue button on the Nucleo board and the message data will be displayed in the Ubuntu terminal.
