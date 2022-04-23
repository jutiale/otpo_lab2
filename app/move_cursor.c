#include "_text.h"
#include <string.h>

void move_cursor(text txt, size_t line, size_t pos)
{	
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    
    
    /* Если список изначально пуст, делать ничего не надо */
    if (line >= txt->length) {
		fprintf(stderr, "Line number is out of text bounds!\n");
        return;
    }
	
    node *current = txt->begin;
	for (size_t i = 0; i < line; i++)
		current = current->next;
	
    if (pos >= strlen(current->contents)) {
		fprintf(stderr, "Cursor position is out ouf line bounds!\n");
        return;
    }
	
    txt->cursor->line = current;
    txt->cursor->position = pos;	
}
