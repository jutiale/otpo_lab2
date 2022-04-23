#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"

void move(text txt, size_t line, size_t pos)
{
	move_cursor(txt, line, pos);
}

