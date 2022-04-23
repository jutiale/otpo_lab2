#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text.h"

// Функция 1 для вывода содержимого текста с нумерацией строк shownum
static void shownum_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    /* Выводим строку на экран */	
	printf("%i ", index);
	int len = strlen(contents);
	for (int i = 0; i < len; i++) {
		if (i == cursor) {
			printf("|");
		}
		printf("%c", contents[i]);
	}
	printf("\n");
}

void shownum(text txt)
{
    process_forward(txt, shownum_line, NULL);
}

// Функция 2 для перемещения курсора на один символ вправо, если это возможно mcf
void mcf(text txt)
{
	move_cursor_right(txt);
}

// Функция 3 для удаления первой строки rh
void rh(text txt)
{
	remove_first(txt);
}
