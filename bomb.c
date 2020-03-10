// Pseudo code of the reversed bomb executable

int main(int argc, char *argv)
{


}

/**
 * Checks if input string is the same as saved pass phrase.
 */
int phase_1(char *s)
{
    if (s == "Public speaking is very easy.")
        return 1;
    else
        explode_bomb();
}

/**
 * Expects six numbers as input. If given less, or if any are not an exact match, the bomb explodes.
 */
int phase_2(char *nums)
{
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
