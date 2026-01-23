#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int max = 0;
    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        int num = 0;
        scanf("%d", &num);

        if(i == 0)
        {
            max = num;
            counter = 1;
            continue;
        }

        if(num > max)
        {
            max = num;
            counter = 1;
        }
        else if(num == max)
            ++counter;
    }
    
    printf("%d\n", counter);
}

