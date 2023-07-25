// Sum of first n natural number.
#include <stdio.h>

int main()
{
    int n = 20,sum = 0;

    for(int i=1; i<=n;i++)
    {
       sum += i;
    }

    printf("The sum of first n natural number is: %d\n", sum);
    return 0;
}