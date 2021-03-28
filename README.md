Калькулятор. Выполнение математического выражения.

# Запуск:

Скачиваем:

```$ git clone https://github.com/DemetryF/evaluate-mathematic-expressions -b dev-3.0 calc```

```$ cd calc```

Компилируем: 

```$ gcc test_programm/main.c -lm -o calc```

Запускаем:

```$ ./calc```

# Описание возможностей:
+ 7 операторов:

    - сумма "+"
    - разность "-"
    - частное "/"
    - произведение "*"
    - деление по модулю "%"
    - деление нацело "\\"
    - возведение в степень "^"

+ Скобочные объеденения: "()"
+ Нецелые числа: "1.2"
+ Константы:
    - число Эйлера "e"
    - число пи "pi"
+ Возможность задавать свои константы используя флаг "-d": "-dvarname=value"

# Части программы

## Лексер
Анализатор входной строки. Сразу проверяет выражение на корректность, проверяя последовательность из 2 токенов: текущая и прошлая, при не разрешенной последовательности будет происходить ошибка "unexped token 'токен' at 'позиция'". 

Каждмому символу присваивает тип, получается токен. Лексер возвращает массив токенов.

Всего используется 5 видов токенов:
+ число: 0-9
+ операторы: "+", "-", "*", "/", "\\", "%", "^"
+ десятичный разделитель: "."
+ скобки: "(" и ")"
+ текст: a-z

## Парсер
Синтаксический анализатор. Составляет так называемое дерево парсинга. Выражение делится на 2 части, пока не останется под-выражений с операторами. Основная идея в том, что с конца строки ищется оператор, с наименьшим приоритетом.

## Солвер
Часть, отвечающая за обработку дерева парсинга. Конечной целью является получение результата от выражения. Используется алгоритм обхода дерева.
Принцип простой: обработв текущую ветку, функция вызывает сама себя для разветвлений.