# Язык программирования C 

<div>
    <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg" width="40" height="40"/>&nbsp;
</div>

<em>Данный репозиторий является конспектом [лекций Сергея Балакирева по языку C](https://www.youtube.com/playlist?list=PLA0M1Bcd0w8w-mqVmBjt-2J8Z1gVmPZVz)</em>

### Установка в Windows

##### Компилятор gcc GNU Compiler Collection

Программа-установщик компилятора <b>minGW</b>
(Добавить в Path путь C:\MinGW\bin)

Для запуска программы на C в PowerShell ввести:

> gcc hello_world.c

> .\a

Чтобы задать свое имя исполняемому файлу:

> gcc hello_world.c -o hw

##### Расширения для VS Code:
* <b>C/C++</b>
* <b>Code Runner</b> (после установки программа компилируется нажатием <b>CTRL + Alt + N</b>)

В .vscode/tasks.json в список args добавить "-std=c99", после этого программа запускается <b>CTRL + Shift + B</b>


### Типы данных

|Тип данных|16 бит|32 бит|64 бит|Описание|Диапазон|
|---|---|---|---|---|---|
|char|1|1|1|Символьный|\[0; 255\] или \[-128; 127\]|
|short\[int\]|2|2|2|Целочисленный|\[-32768; 32767\]|
|int|2|4|4|Целочисленный|\[-32768; 32767\] или \[-2147483648; 2147483648\]|
|long\[int\]|4|4|8|Целочисленный|\[-2147483648; 2147483648\]|
|long long\[int\]|8|8|8|Целочисленный|...|
|float|4|4|4|Вещественный|...|
|double|8|8|8|Вещественный|...|
|long double|10|10|10|Вещественный|...|

##### Модификаторы (только для целочисленных типов):
* <b>unsigned</b> - беззнаковый диапазон
* <b>signed</b> - знаковый диапазон

<em>short, int, long, long long</em> по-умолчанию <b>signed</b>


### Спецификаторы преобразований ввода/вывода

|Спецификатор|Описание|
|---|---|
|<b>%d</b>|Целое число со знаком в десятичной форме (приводится к int)|
|<b>%i</b>|Целое число в десятичной, 8ной или 16ной системах (приводится к int)|
|<b>%u</b>|Целое unsigned число в десятичной форме (приводится к unsigned int)|
|<b>%o</b>|Целое число в 8ной форме (приводится к int)|
|<b>%x</b>, <b>%X</b>|Целое число в 16ной форме (приводится к int)|
|<b>%f</b>, <b>%e</b>, <b>%g</b>, <b>%F</b>, <b>%E</b>, <b>%G</b>|Вещественное число (приводится к float)|
|<b>%c</b>|Символ в соответствии с текущей кодовой таблицей (приводится к char)|
|<b>%s</b>|Строка, читается до первого пробела, перевода строки или табуляции|
|h|%hd, %hi - для short int, %hx, %ho, hu - для unsigned short|
|hh|%hhd - lkz signed char, %hhu - для unsigned char|
|l|%ld, %li - для long int, %lf, %lg, %le -для double|
|L| %Lf, %Lg, %Le - для long double|
|ll (в стандарте C99)|%lld - для long long int, %llu - для unsigned long long|
|Цифры|Максимальная ширина ввода|
|*|Пропуск данных|


### Составные операции сравнения

|Операция|Обозначение|Приоритет (чем выше значение, тем приоритетнее операция)|
|---|---|---|
|ИЛИ|<b>\|\|</b>|1|
|И|<b>&&</b>|2|
|НЕ|<b>!</b>|3|


### Директива `#include`

`#include <stdio.h>` сначала происходит поиск в системных каталогах, затем в рабочем

`#include "utils.h"` сначала происходит поиск в рабочем каталоге, затем в системных

<em>Использовать угловые скобки если необходимо подключить системные файлы, поставляемые с компилятором языка C,
если подключаются собственные файлы, то использовать двойные кавычки.</em>


### Директивы условной компиляции

|Директива|Описание|
|---|---|
|`#if`|Проветка произвольного условия|
|`#else`|Определение условия "иначе"|
|`#endif`|Завершение блока условия|
|`#ifdef`|Проверка на наличие макроимени в текущем модуле|
|`#ifndef`|Проверка на отсутствие макроимени в текущем модуле|
|`#elif`|Аналог else if, определение условия "иначе"|
|`#elifdef`|Проверка на наличие макроимени в условном блоке "иначе"|
|`#elifndef`|Проверка на отсутствие макроимени в условном блоке "иначе"|


### Цикл for

Синтаксис цикла for:

for (<em>инициализация</em>; <em>условие</em>; <em>обновление</em>) {
    // тело цикла
    // операции, которые нужно выполнить на каждой итерации
}

1. <b>инициализация</b> - определение или инициализация переменных, которые будут использоваться в цикле. Обычно этот блок выполняется только один раз в начале цикла.

2. <b>условие</b> - выражение, которое проверяется перед каждой итерацией цикла. Если условие истинно, то тело цикла выполняется. Если условие ложно, то цикл прекращается и исполнение переходит к следующей инструкции после цикла.

3. <b>обновление</b> - операция или изменение переменных, которые должны происходить на каждой итерации цикла. Этот блок выполняется после каждой итерации перед проверкой условия.


### Указатели

<b>Указатель</b> - это <u>переменная, которая хранит адрес</u> другой переменной, массива, функции и другой структуры данных в оперативной памяти. Указатели предназначены для динамического выделения блоков памяти и для оптимизации работы программы.

* `char num = 100`
* `char *nm`          - объявление указателя для работы с типом <b>char</b>
* `nm = &num`         - взятие адреса переменной <b>num</b> и присваивание его указателю <b>nm</b>
* `char x = *nm`      - получение значения по адресу переменной <b>nm</b>
* `*nm = 200`         - запись значения в ячейку, где расположена переменная <b>num</b>

`sizeof()` - Функция, которая расчитывает размер своего аргумента в байтах.


### Строки

<b>Экранирование и спецсимволы</b>

|escape-последовательность|Код ASCII|Описание|
|---|---|---|
|`\n`|0x0A|Перевод на новую строку|
|`\r`|0x0D|Перенос каретки|
|`\t`|0x09|Табуляция|
|`\'`|0x27|Экранирование одинарной кавычки|
|`\"`|0x22|Экранирование двойной кавычки|
|`\?`|0x3F|Экранирование знака вопроса|
|`\\`|0x5C|Экранирование обратного слэша|
|`\0`|0x00|Символ конца строки|
|`\x<число>`||Символ с указанным шестнадцатиричным значением|
|`\uxxxx`||Символ с кодом xxxx в UNICODE (в стандарте C99)|