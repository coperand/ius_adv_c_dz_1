#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n = 0;
    scanf("%u", &n);

    int count = 0;
    for(int i = 0; i < 32; i++)
    {
        if(n & (1 << i))
            count++;
    }
    
    printf("%u\n", count);
}
