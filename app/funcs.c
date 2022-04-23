#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text.h"

static void shownum_line(int index, char *contents, int cursor, void *data);

void shownum(text txt)
{
    process_forward(txt, shownum_line, NULL);
}

void mcf(text txt)
{
	move_cursor_right(txt);
}

void rh(text txt)
{
	remove_first(txt);
}

/**
 * Выводит содержимое указанного файла на экран
 */
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
