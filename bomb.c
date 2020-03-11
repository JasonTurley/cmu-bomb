// Pseudo code of the reversed bomb executable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE (128)

void read_line(char *buf)
{
    fgets(buf, BUF_SIZE, stdin);
    buf[strlen(buf) - 1] = '\0';
}

void explode_bomb()
{
    printf("\nBOOM!!!\n");
    printf("The bomb has blown up.\n");
    exit(8);
}

int strings_not_equal(char *s, char *t)
{
    return strcmp(s, t);
}

void phase_1(char *buf)
{
    if (strings_not_equal(buf, "Public speaking is very easy."))
        explode_bomb();
}

/*
int phase_2(char *nums)
{
    // TODO: make valid C code
    read_six_numbers(nums);

    if (nums[0] != 1)
        explode_bomb()

    for (int i = 1; i <= 5; i++) {
        nums[i] = (i + 1) * nums[i - 1];
        // 1 2 6 24 120 720
    }

    return 1;
}

int phase_3(char *buf)
{
    // TODO: make valid C code
    int x, y;
    char c;

    sscanf(buf, "%d %c %d", x, c, y);

    if (x != 7)
        explode_bomb();

    int n;
    switch (c)

    case 'q':
        n = 113;
    case 'b':
        n = 98;
    case 'k':
        n = 107;
    case 'o':
        n = 111;
}
*/

void phase_defused()
{
    // TODO: implement me
}

int main(int argc, char *argv[])
{
    // TODO check arguments
    char buf[BUF_SIZE];

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n" );

    // Phase 1
    read_line(buf);
    phase_1(buf);
    phase_defused();
    printf("Phase 1 defused. How about the next one?\n");

    // Phase 2
    read_line(buf);


    return 0;
}
