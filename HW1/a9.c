#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int arr[], struct pack_array *result)
{
    for(int i = 0; i < 32; i++)
    {
        result->array |= (arr[i] << (31 - i));
        if(arr[i] == 1)
            result->count1++;
        else
            result->count0++;
    }
}

int main()
{
    int array[32] = {};
    scanf("%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5], &array[6], &array[7],
            &array[8], &array[9], &array[10], &array[11], &array[12], &array[13], &array[14], &array[15], &array[16], &array[17], &array[18], &array[19], &array[20], &array[21], &array[22],
            &array[23], &array[24], &array[25], &array[26], &array[27], &array[28], &array[29], &array[30], &array[31]);

    struct pack_array packed;
    array2struct(array, &packed);
    // printf("%b %u %u\n", packed.array, packed.count0, packed.count1);
    printf("%u %u %u\n", packed.array, packed.count0, packed.count1);
}
