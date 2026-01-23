#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
    uint32_t n;
    scanf("%u", &n);

    if(n > 1000000)
    {
        printf("-1\n");
        return 0;
    }

    uint32_t max_power = 1;
    uint32_t power = 0;
    while(max_power * 3 <= 2000000)
    {
        max_power *= 3;
        power++;
    }

    uint32_t temp = n;
    uint32_t left_sum = 0;
    uint32_t right_sum = 0;
    for(int i = 0; i <= power && temp != 0; i++)
    {
        uint32_t digit = temp % 3;

        if(digit == 1)
        {
            left_sum += pow(3, i);
            temp /= 3;
        } 
        else if (digit == 2)
        {
            right_sum += pow(3, i);
            temp = temp / 3 + 1;
        }
        else
            temp /= 3;
    }

    if (left_sum > 1000000 || right_sum > 1000000)
    {
        printf("-1\n");
        return 0;
    }

    temp = n;
    int count = 0;

    while(temp > 0) {
        int digit = temp % 3;

        if(digit == 1)
        {
            count++;
            temp /= 3;
        } 
        else if(digit == 2)
        {
            count++;
            temp = temp / 3 + 1;
        }
        else
            temp /= 3;
    }

    printf("%d\n", count);
}
