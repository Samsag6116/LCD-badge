/*
 * GXFC.h
 *
 *  Created on: Mar 22, 2017
 *      Author: Spatel1652
 */

#ifndef GXFC_H_
#define GXFC_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "ILI9163.h"
#include "stm32l4xx_hal.h"


#define FastChar
#define LetterSpace 1

 typedef enum{
 	StdFont,
 	Font1,
 } Fonts;

 typedef struct{
 	uint8_t Size;
 	Fonts Font;
 	uint8_t XPos;
 	uint8_t YPos;
 	int8_t Padding;
 	uint8_t Precision;
 	Colours8 TxtCol;
 	Colours8 BkgCol;
 } TextParamStruct;

void TextParamInit(TextParamStruct*);

uint16_t ColIP(Colours8, uint8_t);
uint16_t ColP(uint8_t, uint8_t, uint8_t);
int8_t PStr(const char*, TextParamStruct*);
int8_t PChar(uint16_t, TextParamStruct*);

//int16_t PChar(uint16_t, uint8_t, uint8_t, uint8_t, Colours8, Colours8);
//int16_t PStr(char*, uint8_t, uint8_t, uint8_t, Colours8, Colours8);
int16_t PNum(int32_t, uint8_t, uint8_t, uint8_t, uint8_t, Colours8, Colours8);
int16_t PNumF(float, uint8_t, uint8_t, uint8_t, uint8_t, Colours8, Colours8);

uint8_t Circle(uint8_t, uint8_t, uint8_t, Colours8);
uint8_t FillCircle(uint8_t, uint8_t, uint8_t, Colours8, Colours8);

uint8_t Ellipse(uint8_t, uint8_t, uint8_t, uint8_t, Colours8);
uint8_t FillEllipse(uint8_t, uint8_t, uint8_t, uint8_t, Colours8, Colours8);
uint8_t Semicircle(uint8_t, uint8_t, uint8_t, uint8_t, Colours8);

uint8_t Rect(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t, Colours8);
uint8_t FillRec(uint8_t, uint8_t, uint8_t, uint8_t, Colours8, Colours8);
uint8_t LineP(uint8_t, uint8_t, uint8_t, int16_t, Colours8);
uint8_t LineC(uint8_t, uint8_t, uint8_t, uint8_t, Colours8);
void startWrite(void);
void endWrite(void);
void fillCircle(int16_t x0, int16_t y0, int16_t r, Colours8);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, Colours8);
void writeFastVLine(int16_t x, int16_t y, int16_t h, Colours8);
void drawFastVLine(int16_t x, int16_t y, int16_t h, Colours8);
uint8_t Triangle(uint8_t, uint8_t, uint8_t, uint16_t, Colours8);

uint8_t Row(uint8_t, uint8_t, uint8_t, Colours8);
uint8_t Column(uint8_t, uint8_t, uint8_t, Colours8);

void RotateCo(int32_t *, int32_t *, int32_t);
uint32_t IAbs(int32_t);
int16_t qSin(int32_t);
uint32_t StrLen(char *);
uint8_t CheckNumLength(int32_t);
int32_t FPow(int32_t, uint32_t);

#endif
