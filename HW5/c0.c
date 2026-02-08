#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000

int main()
{
    //Считываем входные данные
    char s[ARRAY_SIZE];
    scanf("%s", s);

    //Заполняем массив флагов, можно ли составить число
    char seen[ARRAY_SIZE] = {0};
    memset(seen, 0, ARRAY_SIZE);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '0')
            continue;

        for(int j = i + 1; j < len; j++)
            for(int k = j + 1; k < len; k++)
            {
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                seen[num] = 1;
            }
    }

    //Подсчитываем количество составленных чисел
    int count = 0;
    for(int num = 100; num <= 999; num++)
        if(seen[num])
            count++;

    printf("%d\n", count);
}
