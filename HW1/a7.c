#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n;
    scanf("%u", &n);

    uint32_t result = 0;
    for(int i = 0; i < n; i++)
    {
        uint32_t num;
        scanf("%u", &num);
        result ^= num;
    }

    printf("%u\n", result);
}
