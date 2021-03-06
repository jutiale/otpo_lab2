/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }
        /* Сохраняем содержимое файла, заданного параметром */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }
		
		char *pos;
		if (strcmp(cmd, "m") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL || (pos = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: m l p\n");
            } else {
                move_cursor(txt, atoi(arg), atoi(pos));
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
		
		/* Выводим текст */
        if (strcmp(cmd, "shownum") == 0) {
            shownum(txt);
            continue;
        }
        
		if (strcmp(cmd, "mcf") == 0) {
            mcf(txt);
            continue;
        }

		if (strcmp(cmd, "rh") == 0) {
            rh(txt);
            continue;
        }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
