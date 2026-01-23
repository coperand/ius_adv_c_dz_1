#include <stdio.h>
#include <stdint.h>

int extractExp(float num)
{
    return (*((uint32_t*)&num) >> 23) & 0xFF;
}

int main()
{
    float num;
    scanf("%f", &num);

    printf("%d\n", extractExp(num));
}
