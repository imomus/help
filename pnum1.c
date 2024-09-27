#include <stdio.h>

int main()
{
    int n;
    int i;
    int c = 0;
    printf("You want prime numbers upto: ");
    scanf("%d",&n);
    if(n < 2)
    {
        printf("The prime number is : NONE\n");
    }
    else
    {
        printf("The prime numbers are: 2");
        for(i =1;i<=n;i++)
        {
                    for(int j =2;j<i;)
                    {
                        if(i%j==0)
                        {
                            break;
                        }
                        j++;
                        if(j==i)
                        {
                            printf(", %d",i);
                            c++;
                        }
                    }
        }
        printf("\n");
        printf("The no. of prime numbers upto %d is %d",n,c+1);
        printf("\n");
    }
}
    