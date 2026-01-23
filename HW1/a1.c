#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d ", &n);

    if(n > 'Z' - 'A' + 1)
        n %= 'Z' - 'A' + 1;

    char a = 0;
    do
    {
        scanf("%c", &a);

        if(a == ' ' || a == '.')
        {
            printf("%c", a);
            continue;
        }

        int upper = a >= 'A' && a <= 'Z';

        int result = a + n;
        if(upper && result > 'Z')
            result = result - 'Z' + 'A' - 1;
        else if(!upper && result > 'z')
            result = result - 'z' + 'a' - 1;

        printf("%c", result);
    }
    while(a != '.');
    printf("\n");
}
