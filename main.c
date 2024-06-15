#include "main.h"

int main(int argc, char *argv[])
{
    // переменные для взятия значений ключей командной строки
    int key              = 0;   // ключ параметра командной строки
    int monthNumber      = 0;   // номер месяца
//============= ОБРАБОТКА ПОАРАМЕТРОВ КОМНАДНОЙ СТРОКИ =============================================
    FILE* textForScan = NULL; // файловый дескриптор для работы с исследуемым файлом
    // считываем значения параметров командной строки
    while ((key = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (key) {
            case 'h': // если включен вывод файла help на консоль
                { // выводим напрямую текст из файла help.txt в консоль
                    PrintFromFile("help.txt");
                }
                break;
            case 'f': 
                textForScan = fopen(optarg, "r");
                break;
            case 'm':
                monthNumber = ConvertStringToNumber(optarg);
                if ((monthNumber < 1) || (monthNumber > 12))
                {
                    printf("Wrong month number!\n");
                    return 1;
                }
                break;
            default:
                break;
        }
    }
    if (argc == 1) {
        printf("\nThis program is designed to analyze temperature sensor statistics.\nPlease specify the \"-h\" key in the parameter to get help\n\n");
        return 0;
    }

    if (textForScan == NULL) {
        printf("You must specify the file with the -f parameter\n");
        return 0;
    }
//==================================================================================================

//======= РАЗЛОЖЕНИЕ ФАЙЛА НА МАССИВ СТРУКТУР ======================================================
    int numbOfStrings = HowManyStrings(textForScan);                    // находим количество строк в исследуемом файле
    sensorData* dataArray = malloc(numbOfStrings * sizeof(sensorData)); // выделяем память под массив структур на numbOfStrings элементов
    int index = 0;                                                      // индекс масссива
    // ЗАПОЛНЯЕМ МАССИВ
    int stringNumber = 1; // номер исследуемой строки
    int rez          = 0; // количество удачно прочитанных значений
    int strIndex     = 0; // индекс перехода по строке
    char str[30];         // буферная строка
    char c;  
    do {
        c = getc(textForScan);
        // формируем строку без пробелов и раскладываем ее на структуру
        if ((c != '\n') && (c != ' ') && (c != EOF)) { // если символ не пробел и не перенос строки 
            str[strIndex++] = c;                 // записываем его в массив буферной строки
        // укладываем сформированную строку в структуру    
        } else if ((c == EOF) || (c == '\n')) {  // если символ - перенос строки или конец файла то дальше парсим строку в структуру
            str[strIndex] = '\0';                // следующий символ в строке заполняем знаком окончания строки чтоб в нашу температуру не попало случайное значение
            strIndex = 0;
            rez = sscanf(str, "%d;%d;%d;%d;%d;%d",
                     &dataArray[index].year,
                     &dataArray[index].month,
                     &dataArray[index].day,
                     &dataArray[index].hour,
                     &dataArray[index].minutes,
                     &dataArray[index].temperature);
            if ((rez == 6)) {
                index++;
            } else {
                printf("Line %d have a problem.\n", stringNumber);
            }
            stringNumber++;
        }
    } while (c != EOF);
    fclose(textForScan);
    int lenghtOfDataArray = index; // фиксируем длину на которую заполнен наш массив структур
//===================================================================================================

//========= ВЫВОД ИНТЕРЕСУЮЩИХ НАС ДАННЫХ НА КОНСОЛЬ ================================================
    if (monthNumber) {
        printf("____________________________________________________\n");
        PrintOutputData(MaxMinAverPreMonth(dataArray, lenghtOfDataArray, monthNumber), monthNumber);
    } else {
        printf("____________________________________________________\n");
        for (int i = 1; i <= 12; ++i) {
            PrintOutputData(MaxMinAverPreMonth(dataArray, lenghtOfDataArray, i), i);
        }
        PrintOutputData(MaxMinAverPreYear(dataArray, lenghtOfDataArray), 0);
    }
//===================================================================================================   
    free(dataArray);
    return 0;
}

