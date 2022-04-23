/**
 * remove_all.c -- реализует функцию очистки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

 
void remove_first(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    
    
    /* Если список изначально пуст, делать ничего не надо */
    if (txt->length == 0) {
        fprintf(stderr, "Text file is empty\n");
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL);

    txt->length = txt->length - 1;
	if (txt->cursor->line == txt->begin)
	{
		txt->cursor->line = txt->begin->next;
		txt->cursor->position = 0;
	}
    node* next = txt->begin->next;
	free(txt->begin);
	txt->begin = next;
}
