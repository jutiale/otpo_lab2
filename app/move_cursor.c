#include "_text.h"
#include <string.h>

void move_cursor_right(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->cursor->line == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }
 
    size_t i = txt->cursor->position + 1;
    if (i >= strlen(txt->cursor->line->contents)) {
		fprintf(stderr, "position + 1 >= line length!\n");
        return;
    }
	
	txt->cursor->position = i;	
}

void move_cursor(text txt, size_t line, size_t pos)
{	
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    
    
    /* Если список изначально пуст, делать ничего не надо */
    if (line >= txt->length) {
		fprintf(stderr, "line >= text length!\n");
        return;
    }
	
    node *current = txt->begin;
	for (size_t i = 0; i < line; i++)
		current = current->next;
	
    if (pos >= strlen(current->contents)) {
		fprintf(stderr, "pos >= line length!\n");
        return;
    }
	
    txt->cursor->line = current;
    txt->cursor->position = pos;	
}
