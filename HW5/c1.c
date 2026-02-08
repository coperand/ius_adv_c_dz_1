#include <stdio.h>
#include <string.h>

#define MAXN 1000

int main()
{
    //Считываем данные
    char s1[MAXN], s2[MAXN];
    memset(s1, 0, MAXN);
    memset(s2, 0, MAXN);
    scanf("%s\n%s", s1, s2);

    //Подсчитываем длины строк
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    //Получаем первый результат
    int ans1 = 0;
    for(int k = (len1 < len2) ? len1 : len2; k >= 1; k--)
        if(strncmp(s1, s2 + len2 - k, k) == 0)
        {
            ans1 = k;
            break;
        }

    //Получаем второй результат
    int ans2 = 0;
    for(int k = (len1 < len2) ? len1 : len2; k >= 1; k--)
        if(strncmp(s1 + len1 - k, s2, k) == 0)
        {
            ans2 = k;
            break;
        }

    //Выводим результаты
    printf("%d %d\n", ans1, ans2);
}
