#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

void
swap (char *text, int a, int b)
{
    char buf;
    buf = text[a];
    text[a] = text[b];
    text[b] = buf;
    return ;
}       /* -----  end of function swap  ----- */

void
reverse (char *text, int begin, int end)
{
    for (; begin<end; begin++,end--)
        swap (text, begin, end);
    return ;
}       /* -----  end of function reverse  ----- */
char *
reverse_word (char * text)
{
    int i = 0;
    int pre_i = i;
    int j = strlen(text)-1;
    int pre_j = j;
    while (i < j && text[i] != ' ') 
        i++;
    reverse(text, pre_i, i-1);
    fprintf (stdout, "text1 : %s\n", text);
    while (i < j && text[j] != ' ')
        j--;
    reverse(text, j+1, pre_j);
    fprintf (stdout, "text2 : %s\n", text);
    while (i <= j) {
        while (pre_i<=i && pre_j>=j)
            swap (text, pre_i++, pre_j--);
        fprintf (stdout, "text3 : %s\n", text);
        if (pre_i > i) {
            i = pre_i;
            while (i < j && text[i] != ' ') 
                i++;
            reverse(text, pre_i, i-1);
            fprintf (stdout, "text4 : %s\n", text);
        } else {
            j = pre_j;
            while (i < j && text[j] != ' ') 
                j--;
            reverse(text, j+1, pre_j);
            fprintf (stdout, "text5 : %s\n", text);
        }
    }
    if (pre_i > i)
        reverse (text, j, pre_j);
    else
        reverse (text, pre_i, i);

    return text;
}       /* -----  end of function reverse_word  ----- */


int
main ( int argc, char *argv[] )
{
    char text[640] = "aaa bbbb eeeeee";
    fprintf (stdout, "text  : %s\n", text);
    fprintf (stdout, "result: %s\n", reverse_word(text));
    return EXIT_SUCCESS;
}               /* ----------  end of function main  ---------- */

