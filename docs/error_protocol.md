# Ошибка №1
* Описание: сохранение нескольких строк
* Тест: модуль save, тест 1
* Входные данные: "12345\n67890"
* Ожидаемый результат: "12345\n67890\n"
* Фактический результат: "1234567890"
* Возможная причина: функция сохранения содержимого строки не добавляет символ новой строки
* Статус: исправлена
