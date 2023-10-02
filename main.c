#include <stdio.h>

int main(void)
{
    double x = 1;
    int *per = (int *)&x;       // Конструкция (int *) - приведение типов, 
                                //                      если типы переменной и указателя отличаются
    printf("per: %d\n", per);   // 6487824

    per++;
    printf("per: %d", per);     // 6487828

    /* 
    Адрес изменился на 4, так как тип указателя на переменную - int,
    Тип int занимает 4 байта в оперативной памяти
    */
    return 0;
}