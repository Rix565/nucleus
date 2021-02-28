#ifndef EDITOR_H
#define EDITOR_H
#include <stdio.h>

typedef struct
{
  char* filename;
} Editor;

void Editor_open(char* filename);
void Editor_save();

#endif
