// собственно основная структура
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int temperature;
} sensorData;

// структура нужных нам данных по месяцам или году
typedef struct {
    int max;
    int min;
    float average;
} outputValue;

/* Переводит строку в число. 
 * Нужно для того что бы получить номер месяца из параметра командной строки 
 */
int ConvertStringToNumber(char*);

/*  
 * Возвращает количетсво строк в исследуемом файле 
 */
int HowManyStrings(FILE*);

/*  
 * Возвращает структуру данных за указанный месяц  
 */
outputValue MaxMinAverPreMonth(sensorData*, int, int);

/*  
 * Возвращает структуру данных за год
 */
outputValue MaxMinAverPreYear(sensorData*, int);

/*  
 * Выводи на экран статистику за указанный месяц,
 * или за год если указать 0.
 */
void PrintOutputData(outputValue, int);

/*  
 * Просто вводит на экран текст из файла
 */
void PrintFromFile(char*);