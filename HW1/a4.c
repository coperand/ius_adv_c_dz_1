#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n = 0;
    uint32_t k = 0;
    scanf("%u %u", &n, &k);

    uint32_t max = 0;

    for(int i = 0; i <= 32 - k; i++)
    {
        uint32_t bits = (n & (((1u << k) - 1) << i)) >> i;

        if(bits > max)
            max = bits;
    }
    
    printf("%u\n", max);
}
