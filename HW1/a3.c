#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n = 0;
    uint32_t k = 0;
    scanf("%u %u", &n, &k);

    int junior_bits = n & ((1 << k) - 1);

    printf("%u\n", junior_bits);
}
