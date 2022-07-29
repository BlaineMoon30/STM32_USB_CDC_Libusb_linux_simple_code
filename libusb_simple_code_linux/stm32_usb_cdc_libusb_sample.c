/**
  ******************************************************************************
  * @file    stm32_usb_cdc_libusb_sample.c
  * @author  MCD Application Team 
  * @brief        
  *      
  @verbatim
  ==============================================================================
                     ##### <stm32_usb_cdc_libusb_sample.c> features #####
  ==============================================================================
  [..]
    Sample
    (+) Sample
        (++) Sample

                     ##### How to use this <stm32_usb_cdc_libusb_sample.c> #####
  ==============================================================================
  [..]
    Sample
    (+) Sample
        (++) Sample   

                     ##### <stm32_usb_cdc_libusb_sample.c> Limitations #####
  ==============================================================================
  [..]
    Sample
    (+) Sample
        (++) Sample   

  @endverbatim 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/
#define USB_VENDOR_ID           1155
#define USB_PRODUCT_ID          22336

#define CDC_IN_EP               0x81
#define CDC_OUT_EP              0x01

#define RECEIVE_CNT             5

/* Private macro -------------------------------------------------------------*/


/* Exported variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
static libusb_context *ctx = NULL;
static libusb_device_handle *handle;
static libusb_device **devs;

/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/


/* External functions --------------------------------------------------------*/

/**
  * @brief  
  * @param  
  * @retval None
  */
int main(int argc, char *argv[])
{
  int ret_val = 0, ret_cnt = 0;
  unsigned char receive_buf[100];
  int init = libusb_init(NULL);

  printf("STM32 CDC libUSB test with STM32H723-Nucleo Board \n\n\n");

  if (init < 0)
  {
    printf("libusb Initialize failed \n\n");
  }

  handle = libusb_open_device_with_vid_pid(NULL, USB_VENDOR_ID, USB_PRODUCT_ID);
  if (handle == NULL)
  {
    printf("Device not found1\n\n");
    return 1;
  }
  else
  {
    printf("Device Found !!\n\n");
  }

  ret_val = libusb_kernel_driver_active(handle, 0);
  if (ret_val == 1)
  {
    libusb_detach_kernel_driver(handle, 0);
    printf("driver error");
  }

  for (ret_cnt = 0; ret_cnt < RECEIVE_CNT; ret_cnt++)
  {
    ret_val = libusb_bulk_transfer(handle, CDC_IN_EP, receive_buf, 40, NULL, 0);
    if (ret_val < 0)
    {
      printf("%s\n", libusb_error_name(ret_val));
    }
    printf("receive idx = %d data = %s\n",ret_cnt, receive_buf);
  }

  printf("Finish!! \r\n");
  return 0;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
