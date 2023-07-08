#include <stdio.h>

void three_dimensional()
{
    int c[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};
    int (*p)[2][2] = c;

    // c[i][j][k] = *(*(*(c + i) + j) + k)

    printf("%d\n", c); // p int(*)[2][2]
    printf("%d\n", *c); // c[0] or &c[0][0] / int (*)[2]
    printf("%d\n", *(c[0][1] + 1)); // 9 / or c[0][1][1]
    printf("%d\n", *(c[1] + 1)); // &c[1][1][0] / or c[1][1]

    return;
}

int main(int argc, char** argv)
{


    return 0;
}