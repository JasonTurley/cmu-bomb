// Pseudo code of the reversed bomb executable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define BUF_SIZE (128)

// TODO
// implement sighandler
void sig_handler(int signo)
{
    if (signo == SIGINT) {

        printf("So you think you can stop the bomb with ctrl-c, do you?\n");
        sleep(4);

        printf("Well...");
        fflush(stdout);
        sleep(2);

        printf("OK. :-)\n");

        exit(16);
    }
}

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

void read_six_numbers(char *buf, int *nums)
{
    int nums_read = sscanf(buf, "%d %d %d %d %d %d", &nums[0], &nums[1],
            &nums[2], &nums[3], &nums[4], &nums[5]);

    if (nums_read != 6)
        explode_bomb();
}

void phase_2(char *buf)
{
    int nums[6];

    // TODO: make valid C code
    read_six_numbers(buf, nums);

    if (nums[0] != 1)
        explode_bomb();

    for (int i = 1; i <= 5; i++) {
        nums[i] = (i + 1) * nums[i - 1];
        // 1 2 6 24 120 720
        // TODO: check each iteration of results
    }
}

/*
int phase_3(char *buf)
{
    // TODO: make valid C code
    int x = 0;
    int y = 0;
    char c;

    sscanf(buf, "%d %c %d", &x, &c, &y);

    if (x != 7)
        explode_bomb();

    int n;
    switch (c) {

    case 'q':
        n = 113;
    case 'b':
        n = 98;
    case 'k':
        n = 107;
    case 'o':
        n = 111;
    default:
        n = 0;
    }

    return n;
}
*/

int func4(int x)
{
    // fib sequence?
    return x;
}

void phase_4(char *s)
{
    int x = 0;
    int retval; // eax

    retval = sscanf(s, "%d", &x);

    if (retval != 1)
        explode_bomb();

    if (x < 0)
        explode_bomb();

    retval = func4(x);

    if (retval != 55)
        explode_bomb();
}

void phase_defused()
{
    // TODO: implement me
}

int main(int argc, char *argv[])
{
    // TODO check arguments
    char buf[BUF_SIZE];

    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        fprintf(stderr, "Failed to handle SIGINT\n");
        exit(1);
    }

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n" );

    // Phase 1
    read_line(buf);
    phase_1(buf);
    phase_defused();
    printf("Phase 1 defused. How about the next one?\n");

    // Phase 2
    read_line(buf);
    phase_2(buf);

    return 0;
}
