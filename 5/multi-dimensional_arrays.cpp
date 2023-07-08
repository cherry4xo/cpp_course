#include <stdio.h>

void one_demenssional()
{
    // things we need to know 
    int a[5] = {2, 4, 6, 8, 10};
    int* p = a;
    printf("%d\n", p); // is equals printf("%d\n", a);
    printf("%d\n", *p); // printf("%d\n", *a);
    printf("%d\n", *(p + 2)); // printf("%d\n", *(a + 2));
    // *(a + i) is equals a[i]
    // (a + i) is equals &a[i]

    return;
}

void two_demensional()
{   
    int b[2][3] = {{2, 3, 6}, {4, 5, 8}};
    // b[0] and b[1] are 1-d arrays of 3 int
    // int* p = b; is not valid
    int (*p)[3] = b;
    printf("%d\n", b);
    // print b or &b[0]
    printf("%d\n", **b);
    // print *b or b[0][0] or &b[0][0]
    printf("%d\n", b + 1);
    // b + 1 will be b + 3 * sizeof(int)
    printf("%d\n", *(b + 1));
    // *(b + 1) will be 4 or b[1] or &b[1][0]
    printf("%d\n", *(b + 1) + 2);
    // print *(b + 1) + 2 will be b + 3 * sizeof(int) + 2 or b[1] + 2 or &b[1][2]
    printf("%d\n", *(*b + 1));
    //print *(*b + 1) will be 3 equals b[0][1]

    // b[i][j] == *(b[i] + j) == *(*(b + i) + j)

    return;
}

int main(int agrc, char** argv)
{
    two_demensional();


    return 0;
}