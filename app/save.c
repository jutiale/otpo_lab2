/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"

static void saveline(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    
    /* Выводим строку на экран */
    fputs(contents, data);
    fputs("\n", data);
}
/**
 * Загружает содержимое указанного файла
 */
void save(text txt, char *filename)
{
    FILE *f;


    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "a")) == NULL) {
        fprintf(stderr, "The file %s cannot be opened\n", filename);
        return;
    }

	process_forward(txt, saveline, f);
	fclose(f);
}

