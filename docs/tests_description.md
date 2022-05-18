# Модуль shownum
## Метод «Белый ящик»
### Тест №1
* Цель: проверить вывод команды
* Тип: позитивный
* Входные данные: "1\n2\n3"
* Ожидаемый результат: "0 1\n1 2\n2 3\n"
### Тест №2
* Цель: проверить вывод команды при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: наличие сообщения об ошибке
# Модуль mcf
## Метод «Белый ящик»
### Тест №1
* Цель: проверить вывод команды
* Тип: позитивный
* Входные данные: "12345", курсор на позиции 0 0
* Ожидаемый результат: "1|2345\n"
### Тест №2
* Цель: проверить вывод команды в случае нахождения курсора на границе строки
* Тип: негативный
* Входные данные: "12345", курсор на позиции 0 4
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №3
* Цель: проверить вывод команды при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №4
* Цель: проверить вывод команды в случае пустого текста
* Тип: негативный
* Входные данные: ""
* Ожидаемый результат: наличие сообщения об ошибке
# Модуль rh
## Метод «Белый ящик»
### Тест №1
* Цель: проверить вывод команды
* Тип: позитивный
* Входные данные: "12345\n67890", курсор на позиции 0 0
* Ожидаемый результат: "|67890\n"
### Тест №2
* Цель: проверить вывод команды в случае отсутствия строк
* Тип: негативный
* Входные данные: ""
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №3
* Цель: проверить вывод команды при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: наличие сообщения об ошибке
# Модуль save
## Метод «Белый ящик»
### Тест №1
* Цель: проверить вывод команды
* Тип: позитивный
* Входные данные: "12345\n67890"
* Ожидаемый результат: файл с содержимым "12345\n67890\n"
### Тест №2
* Цель: проверить вывод команды при пустом файле
* Тип: негативный
* Входные данные: ""
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №3
* Цель: проверить вывод команды при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №4
* Цель: проверить вывод команды в случае ошибки чтения файла
* Тип: негативный
* Входные данные: filename = "/qwerty"
* Ожидаемый результат: наличие сообщения об ошибке
# Модуль m
## Метод «Белый ящик»
### Тест №1
* Цель: проверить вывод команды
* Тип: позитивный
* Входные данные: "12\n34\n56\n78", курсор на позиции 2 1
* Ожидаемый результат: "12\n34\n5|6\n78\n"
### Тест №2
* Цель: проверить вывод команды при пустом файле
* Тип: негативный
* Входные данные: "", установить курсор на позицию 0 0
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №3
* Цель: проверить вывод команды при отсутствии файла
* Тип: негативный
* Входные данные: txt = NULL
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №4
* Цель: проверить вывод команды при попытке установить курсор на несуществующую линию
* Тип: негативный
* Входные данные: "1\n2", установить курсор на позицию 999 0
* Ожидаемый результат: наличие сообщения об ошибке
### Тест №5
* Цель: проверить вывод команды при попытке установить курсор на несуществующий символ
* Тип: негативный
* Входные данные: "1\n2", установить курсор на позицию 0 999
* Ожидаемый результат: наличие сообщения об ошибке