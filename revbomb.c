// My attempt at reverse engineering the binary bomb into valid C code.
// Note - this is an educational exercise and much of the code is currently
// buggy. This will be amended over time.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define BUF_SIZE (128)

/**
 * Catches the Ctrl-C (SIGINT) signal.
 */
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

/**
 * Read a line of text from the file, or from stdin if no file is given.
 */
void read_line(char *buf, FILE *file)
{
    if (file)
        fgets(buf, BUF_SIZE, file);
    else
        fgets(buf, BUF_SIZE, stdin);

    buf[strlen(buf) - 1] = '\0';
}

/**
 * Detonates the bomb, effectively ending the game. Called when the player
 * incorrectly answers a phase.
 */
void explode_bomb()
{
    printf("\nBOOM!!!\n");
    printf("The bomb has blown up.\n");
    exit(8);
}

/**
 * Wrapper for strcmp.
 */
int strings_not_equal(char *s, char *t)
{
    return strcmp(s, t);
}

/**
 * The first phase of the binary bomb game.
 *
 * Checks if the player enters the correct string passphrase.
 */
void phase_1(char *buf)
{
    if (strings_not_equal(buf, "Public speaking is very easy."))
        explode_bomb();
}

/**
 * Helper function for phase_2. Reads the first six numbers entered by the
 * player and stores them in the `nums` return argument.
 *
 * If the player enters less than six numbers, the bomb explodes.
 * If the player enters more than six numbers, the rest are ignored.
 */
void read_six_numbers(char *buf, int *nums)
{
    int nums_read = sscanf(buf, "%d %d %d %d %d %d", &nums[0], &nums[1],
            &nums[2], &nums[3], &nums[4], &nums[5]);

    if (nums_read != 6)
        explode_bomb();
}

/**
 * The second phase of the binary bomb game.
 *
 */
void phase_2(char *buf)
{
    int nums[6];
    int solution[] = {2, 6, 24, 120, 720};

    read_six_numbers(buf, nums);

    if (nums[0] != 1)
        explode_bomb();

    for (int i = 1; i < 6; i++) {
        nums[i] = (i+1) * nums[i-1];

        if (nums[i] != solution[i-1])
            explode_bomb();
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
    FILE *input_file = NULL;

    if (argc > 2) {
        printf("Usage: ./bomb [<input_file>]\n");
        exit(8);
    }

    if (argc == 2) {
        input_file = fopen(argv[1], "r");

        if (!input_file) {
            fprintf(stderr, "%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    }

    // Setup signal handler
    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        fprintf(stderr, "Failed to handle SIGINT\n");
        exit(1);
    }

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n" );

    // Phase 1
    read_line(buf, input_file);
    phase_1(buf);
    phase_defused();
    printf("Phase 1 defused. How about the next one?\n");

    // Phase 2
    read_line(buf, input_file);
    phase_2(buf);
    printf("That's number 2.  Keep going!\n");

    return 0;
}
