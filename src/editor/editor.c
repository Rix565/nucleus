#include "editor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Editor editor; /* We want to create a new editor config */

void Editor_open(char *filename)
{
    free(editor.filename);

    editor.filename = strdup(filename); /* duplicate filename to editor.filename */

    FILE *fp = fopen(filename, "r"); /* open the file with "r" (read-only mode) */

    char *line = NULL;
    size_t line_length = 0, linecap = 0;

    while ((line_length = getline(&line, &linecap, fp)) != -1)
    {

        while (line_length > 0 && (line[line_length - 1] == '\n' ||
                                   line[line_length - 1] == '\r'))
            line_length--;

        printf("%s", line); /* GUI "insert line" will be here instead of printf */
    }

    /* Freeing the line pointer & closing the file */
    free(line);
    fclose(fp);
}

void Editor_save()
{
    if (editor.filename == NULL)
    {
      /* TODO: "prompt" GUI function so that we can prompt the user */
      printf("Please enter a name for your file");
    }

    /* TODO: GUI Function to get the text in the current buffer */

    
    
}
