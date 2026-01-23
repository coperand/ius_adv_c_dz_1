#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n = 0;
    scanf("%u", &n);

    unsigned int inv_high_byte = ((n >> 24) & 0xFF) ^ 0xFF;
    unsigned int result = (n & 0x00FFFFFF) | (inv_high_byte << 24);
    
    printf("%u\n", result);
}
