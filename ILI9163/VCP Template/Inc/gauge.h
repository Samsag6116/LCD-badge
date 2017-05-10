/*
 * gauge.h
 *
 *  Created on: Apr 18, 2017
 *      Author: Spatel1652
 */

#ifndef GAUGE_H_
#define GAUGE_H_
#include "ILI9163.h"

#define PI 3.14159265358979323846

void faceHelper(uint8_t x,uint8_t y,uint8_t r,int from,int to,float dev);
void drawNeedle(int16_t val,uint8_t x,uint8_t y,uint8_t r,Colours8 LCol,Colours8 FCol);
void drawPointerHelper(int16_t val,uint8_t x,uint8_t y,uint8_t r,uint16_t color);
#endif /* GAUGE_H_ */
