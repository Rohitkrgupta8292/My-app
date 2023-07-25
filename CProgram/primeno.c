// the number is prime or non prime.
#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the number: ");
    scanf("%d", &n);

    for(i=2; i<n; i++)
    {
        if(n%i==0)
        {
            printf("%d is not a prime number\n", n);
            break;
        }
    }
    if(i==n)
    {
        printf("%d is prime a number\n", n);
    }   
    return 0;    
}