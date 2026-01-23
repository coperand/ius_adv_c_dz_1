#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n = 0;
    uint32_t k = 0;
    scanf("%u %u", &n, &k);

    int shifted = (n >> k) | (n << (32 - k));

    printf("%u\n", shifted);
}
