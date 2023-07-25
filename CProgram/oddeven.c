#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    if(n%2 == 0)
    {
        printf("%d is Even Number\n", n);
    }
    else
    {
        printf("%d is Odd Number\n", n);
    }
    
    return 0;
}