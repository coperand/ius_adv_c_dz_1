#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //Считываем данные
    char s[10000];
    memset(s, 0, sizeof(s));
    scanf("%[^\n].", s);

    //Стек чисел
    int stack[10000];
    int top = 0;

    //Перебираем "слова"
    char* word = strtok(s, " \t\n\r");
    while(word != NULL)
    {
        //Если это число
        if (isdigit(word[0]) || (strlen(word) > 1 && isdigit(word[1])))
            stack[top++] = atoi(word);
        //Если это оператор
        else
        {
            int b = stack[--top];
            int a = stack[--top];
            int res = 0;
            switch(word[0])
            {
                case '+':
                {
                    res = a + b;
                    break;
                }
                case '-':
                {
                    res = a - b;
                    break;
                }
                case '*':
                {
                    res = a * b;
                    break;
                }
                case '/':
                {
                    res = a / b;
                    break;
                }
            }
            stack[top++] = res;
        }

        word = strtok(NULL, " \t\n\r");
    }

    //Выводим результат
    printf("%d\n", stack[0]);
}
