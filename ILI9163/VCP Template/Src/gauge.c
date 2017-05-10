/*
 * gauge.c
 *
 *  Created on: Apr 18, 2017
 *      Author: Spatel1652
 */
#include "stm32l4xx_hal.h"

#include "gauge.h"
#include"GFXC.h"

#include "MATH.H"
#include <stdlib.h>

 int16_t curVal1 ;
 int16_t oldVal1 ;



  void faceHelper(uint8_t x,uint8_t y,uint8_t r,int from,int to,float dev)
  {
	       float dsec,fromSecX,fromSecY,toSecX,toSecY;
	       int i;
	       for (i = from;i <= to;i += 30) {
	         dsec = i * (PI / 180);
	         fromSecX = cos(dsec) * (r / dev);
	         fromSecY = sin (dsec) * (r / dev);
	         toSecX = cos (dsec) * r;
	         toSecY = sin (dsec) * r;
	         LineC(1 + x + fromSecX,1 + y + fromSecY,1 + x + toSecX,1 + y + toSecY,White);
	       }
	     }
	   void drawGauge(uint8_t x,uint8_t y,uint8_t r)
	   {
	     Circle(x, y, r,White);//draw instrument container
	     faceHelper(x,y,r,150,390,1.3); //draw major ticks
	     if (r > 15) faceHelper(x,y,r,165,375,1.1); //draw minor ticks

	   }
	   void drawPointerHelper(int16_t val,uint8_t x,uint8_t y,uint8_t r,uint16_t color)
	   {
	  	     float dsec, toSecX, toSecY;
	  	     int16_t minValue = 0;
	  	     int16_t maxValue = 255;
	  	     int fromDegree = 150;//start
	  	     int toDegree = 240;//end
	  	     if (val > maxValue) val = maxValue;
	  	     if (val < minValue) val = minValue;
	  	     dsec = (((float)(uint16_t)(val - minValue) / (float)(uint16_t)(maxValue - minValue) * toDegree) + fromDegree) * (PI / 180);
	  	     toSecX = cos(dsec) * (r / 1.35);
	  	     toSecY = sin(dsec) * (r / 1.35);
	  	     LineC(x, y, 1 + x + toSecX, 1 + y + toSecY, color);
	  	     fillCircle(x,y,2,color);
	  	   }

	   void drawNeedle(int16_t val,uint8_t x,uint8_t y,uint8_t r,Colours8 LCol,Colours8 FCol)
	   {
	     uint8_t i;
	     if (curVal1 > oldVal1){
	       for (i = oldVal1; i <= curVal1; i++){
	         drawPointerHelper(i-1,63,63,63,FCol);
	         drawPointerHelper(i,63,63,63,LCol);
	         if ((curVal1 - oldVal1) < (128)) HAL_Delay(1);//ballistic
	       }
	     }
	     else {
	       for (i = oldVal1; i >= curVal1; i--){
	         drawPointerHelper(i+1,63,63,63,FCol);
	         drawPointerHelper(i,63,63,63,LCol);
	         //ballistic
	         if ((oldVal1 - curVal1) >= 128){
	          HAL_Delay(1);
	         } else {
	          HAL_Delay(3);
	         }
	       }
	     }
	   }
