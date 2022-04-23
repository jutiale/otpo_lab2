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
		fprintf(stderr, "Cannot move cursor to the right. You have met the end of line.\n");
        return;
    }
	
	txt->cursor->position = i;	
}