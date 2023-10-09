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


### size_t

`size_t` является беззнаковым целочисленным типом данных, используемым для представления размеров объектов в памяти. Он выбирается таким образом, чтобы быть достаточно большим, чтобы вместить размер любого объекта в памяти. Обычно `size_t` имеет размер, достаточный для представления максимального возможного размера массива или объекта данных, который может быть выделен в памяти.

`size_t` широко используется вместе с операторами `sizeof` и в функциях, которые выполняют операции на памяти, таких как `malloc`, `memcpy`, `strlen` и другие, чтобы представить и возвращать размеры объектов в памяти.


### static и extern

Ключевые слова `static` и `extern` относятся к спецификаторам доступа переменных и функций. 

`static`:
* Если `static` используется с переменной внутри функции, то эта переменная становится локальной статической. Она сохраняет свое значение между вызовами функции и инициализируется только один раз.
* Если `static` используется с глобальной переменной или функцией, они становятся доступными только в текущем файле (имеют внутреннюю видимость). Такие переменные и функции не могут быть использованы или видимы из других файлов.

`extern`:
* Используется для объявления переменной или функция, которая определена в другом файле.
* Когда переменная или функция объявлена как `extern`, компилятор знает, что она будет определена в другом месте и можно использовать без ошибки "повторного определения".
* Также используется для доступа к глобальным переменным или функциям, объявленным в других модулях.


### enum

Ключевое слово `enum` используется для определения пользовательских наборов именованных констант, которые представляют собой список значений. Такое перечисление может использоваться для лучшей читаемости кода и упрощения работы с константами.


### typedef

Ключевое слово `typedef` используется для создания псевдонима для существующего типа данных. Это может быть полезно для упрощения именования сложных типов данных или улучшения портативности кода.

`typedef unsigned int uint32_t;`

В этом примере создается псевдоним <b>uint32_t</b> для типа `unsigned int`. Теперь можно использовать <b>uint32_t</b> вместо `unsigned int` для объявления переменных или функций.

Использование псевдонимов с помощью `typedef` может сделать код более понятным и гибким.


### Структуры

Структура - это составной тип данных, который позволяет объединить несколько переменных разных типов в одну логическую единицу. Структура определяется с помощью ключевого слова `struct` и может содержать одно или несколько полей (переменных), каждое из которых имеет свое имя и тип данных.

Пример объявления структуры в C:

```c
struct person {
    char name[50];
    int age;
    float height;
};
```

Здесь объявляется структура `person`, которая содержит три поля: `name` типа `char[50]`, `age` типа `int` и `height` типа `float`.

Чтобы создать переменную типа структуры, используется объявленное имя структуры, за которым следует имя переменной:

```c
struct person person1;
```

Затем можно получить доступ к полям структуры с помощью оператора точки:

```c
strcpy(person1.name, "John");
person1.age = 30;
person1.height = 180.5;
```

Также можно объявить структуру с помощью `typedef`, чтобы использовать созданный тип структуры, не указывая ключевое слово `struct` при объявлении переменных:

```c
typedef struct {
    char name[50];
    int age;
    float height;
} PERSON;
```

Теперь можно создать переменные типа `PERSON` без использования `struct`:

```c
PERSON person2;
```

Структуры полезны для организации данных и создания пользовательских типов, которые могут содержать несколько связанных данных внутри себя.


### Работа с файлами

|Режим|Описание|
|---|---|
|"r"|Открытие текстового файла только на чтение.|
|"w"|Открытие текстового файла только на запись. Если файл не существует, то он создается. Если существует, то все его прежнее содержимое удаляется.|
|"a"|Открытие текстового файла на дозапись (новые данные добавляются в конец файла). Если файл не существует, то он создается.|
|"r+"|Открытие текстового файла для чтения и записи одновременно.|
|"w+"|Открытие текстового файла для чтения и записи. Если файл не существует, то он содается. Если существует, то все содержимое удаляется.|
|"a+"|Открытие текстового файла для чтения и записи. Добавлять данные можно только после имеющегося содержимого. Читать можно все данные. Если файл не существует, то он создается.|