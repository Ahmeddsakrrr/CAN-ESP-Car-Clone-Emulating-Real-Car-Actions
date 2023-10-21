/*
 * app_config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Hossam Elwahsh
 */

#ifndef INC_APP_CONFIG_H_
#define INC_APP_CONFIG_H_

#include "std.h"

/* CAN CONFIG */
#define APP_TX_DATA_LENGTH	8
#define APP_RX_DATA_LENGTH 	8

/* CAR CAN MSG IDS */
#define APP_CAN_ID_THROTTLE 		0x1F0
#define APP_CAN_ID_LIGHTS			0x73E
#define APP_CAN_ID_TRANSMISSION		0x2EF
#define APP_CAN_ID_STEERING			0x0DE

/* CAR CAN TRANSMISSION STATES */
#define APP_CAR_TRANSMISSION_PARK		0xFF
#define APP_CAR_TRANSMISSION_REVERSE	0x7F
#define APP_CAR_TRANSMISSION_NEUTRAL	0x0F
#define APP_CAR_TRANSMISSION_DRIVE		0x1F

/* CAR CAN STEERING THRESHOLDS */
#define APP_CAR_STEERING_THRESHOLD_SHARP_LEFT_MAX	0x2C
#define APP_CAR_STEERING_THRESHOLD_SHARP_LEFT_MIN	0x27
#define APP_CAR_STEERING_THRESHOLD_LEFT_MAX			0x26
#define APP_CAR_STEERING_THRESHOLD_LEFT_MIN			0x21
#define APP_CAR_STEERING_THRESHOLD_SHARP_RIGHT_MAX	0x10
#define APP_CAR_STEERING_THRESHOLD_SHARP_RIGHT_MIN	0x09
#define APP_CAR_STEERING_THRESHOLD_RIGHT_MAX		0x18
#define APP_CAR_STEERING_THRESHOLD_RIGHT_MIN		0x11
#define APP_CAR_STEERING_THRESHOLD_STRAIGHT_MAX		0x20
#define APP_CAR_STEERING_THRESHOLD_STRAIGHT_MIN		0x19


/* ESP FRAME HEADERS */
#define APP_ESP_HEADER_TRANSMISSION			0x07
#define APP_ESP_HEADER_LIGHT_BRAKES			0x08
#define APP_ESP_HEADER_LIGHT_R_INDICATORS	0x09
#define APP_ESP_HEADER_LIGHT_L_INDICATORS	0x0A
#define APP_ESP_HEADER_LIGHT_HAZARD			0x0B
#define APP_ESP_HEADER_LIGHT_FRONT			0x0C
#define APP_ESP_HEADER_LIGHT_REVERSE		0x0D
#define APP_ESP_HEADER_STEERING				0x0E

/* ESP FRAME DATA VALUES */
/* - Steering */
#define APP_ESP_DATA_STEERING_STRAIGHT		0x00
#define APP_ESP_DATA_STEERING_SHARP_LEFT	0x0C
#define APP_ESP_DATA_STEERING_LEFT			0x08
#define APP_ESP_DATA_STEERING_SHARP_RIGHT	0x03
#define APP_ESP_DATA_STEERING_RIGHT			0x02

/* UART OPTIONS */
#define APP_UART_TX_QUEUE_LENGTH			(50)

/* RTOS OPTIONS */
#define APP_RTOS_TASK_STACK_SIZE	(200)

/* throttle mapping scale factor */
#define THROTTLE_READING_REDUCTION_FACTOR 	250 * 64UL

/* helping macro functions */
#define SHIFT_HIGH_NIBBLE_TO_LOW(u8_val) (u8_val >> 4)
#define GENERATE_ESP_FRAME(header, data) ((header & 0x0F) << 4) | (data)
#define GET_CHANGED_BITS(old_val, new_val) (old_val ^ new_val)
#define IS_SINGLE_CHANGED_BIT(value) (!( (value) & (value - 1) ))
#define TOGGLE(value) (value ^= 1)


#endif /* INC_APP_CONFIG_H_ */