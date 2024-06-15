#include "main.h"


int ConvertStringToNumber(char* str){
    int lenght = strlen(str);
    int number = 0;
    for (int i = 0; i < lenght; ++i) {
         number = (number * 10) + (str[i] - 0x30);
    }
    return number;
}

int HowManyStrings(FILE* fp) {
    char c;
    int count = 1; 
    while ((c = getc(fp)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(fp);
    return count;
}

outputValue MaxMinAverPreMonth(sensorData* dataArray, int lenght, int month) {

    outputValue out;

    out.max     = -99;
    out.min     =  99;
    out.average =   0;
    long sum    =   0;
    int count   =   0;

    for (int i = 0; i < lenght; ++i) {
        if (dataArray[i].month == month) {
            out.max = out.max < dataArray[i].temperature ? dataArray[i].temperature : out.max;
            out.min = out.min > dataArray[i].temperature ? dataArray[i].temperature : out.min;
            sum += dataArray[i].temperature;
            count++;
        }
    }
    if (count == 0) {
        out.max     = 0;
        out.min     = 0;
        out.average = 0;
        return out;
    }
    out.average = (1. * sum) / count;
    return out;
}

outputValue MaxMinAverPreYear(sensorData* dataArray, int lenght) {
    
    outputValue out;
    
    out.max     = -99;
    out.min     =  99;
    out.average =   0;
    long long sum    =   0;
    int count   =   0;   

    for (int i = 0; i < lenght; ++i) {
        out.max = out.max < dataArray[i].temperature ? dataArray[i].temperature : out.max;
        out.min = out.min > dataArray[i].temperature ? dataArray[i].temperature : out.min;
        sum += dataArray[i].temperature;
        count++;
    }
    out.average =(1. * sum) / lenght;
    return out;
}

void PrintOutputData(outputValue out, int month) {
    switch (month) {
        case 0:
            printf("\n=====================================================\n");
            printf("Statisctic for the Year:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            printf("=====================================================\n");
            break;
        case 1:
            printf("\nStatisctic for the January:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 2:
            printf("\nStatisctic for the February:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 3:
            printf("\nStatisctic for the March:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 4:
            printf("\nStatisctic for the April:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 5:
            printf("\nStatisctic for the May:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 6:
            printf("\nStatisctic for the June:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 7:
            printf("\nStatisctic for the July:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 8:
            printf("\nStatisctic for the August:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 9:
            printf("\nStatisctic for the September:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 10:
            printf("\nStatisctic for the October:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 11:
            printf("\nStatisctic for the November:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
        case 12:
            printf("\nStatisctic for the December:\n");
            printf("Max value:%3d, Min value:%3d, Average value:%6.2f\n", out.max, out.min, out.average);
            break;
    }
}

void PrintFromFile(char* file) {
    char c;
    char *help = file;
    FILE *fp = fopen(help, "r");
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);
}