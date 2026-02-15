#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Размер контейнера под слово
#define WORD_LEN 20
//Размер контейнера под вводимые данные
#define INPUT_LEN 1000

//Структура списка
struct list {
    char word[WORD_LEN];
    struct list *next;
};

//Головной элемент списка
struct list *head = NULL;

//Функция добавления в список
int add_to_list(char *word)
{
    //Выделяем память под новую запись
    struct list *new_entry = (struct list *)calloc(sizeof(struct list), 1);
    if(!new_entry)
        return -1;

    //Заполняем запись
    strncpy(new_entry->word, word, WORD_LEN - 1);

    //Добавляем новую запись в начало списка
    new_entry->next = head;
    head = new_entry;
    return 0;
}

void swap_elements(struct list *one, struct list *another)
{
    //Копируем слово из первой записи во временный буфер
    char tmp[WORD_LEN];
    strcpy(tmp, one->word);

    //Обмениваем значения между собой
    strcpy(one->word, another->word);
    strcpy(another->word, tmp);
}

void print_list()
{
    //Перебираем записи списка, начиная с головной
    struct list *cur = head;
    while(cur != NULL)
    {
        //Выводим слово
        printf("%s ", cur->word);

        //Переходим к следующей записи
        cur = cur->next;
    }

    //Добавляем в конце перевод строки
    printf("\n");
}

void delete_list()
{
    //Удаляем элементы списка, пока он не станет пуст
    while(head != NULL)
    {
        //Сохраняем указатель на первый элемент для удаления
        struct list *tmp = head;

        //Сдвигаем указатель на головной элемент
        head = head->next;

        //Удаляем первый элемент
        free(tmp);
    }
}

void sort_list()
{
    //Если список пуст, выходим
    if(!head)
        return;

    //Проходимя по всем элементам списка и меняем их местами при необходимости
    for(struct list *i = head; i != NULL; i = i->next)
        for(struct list *j = i->next; j != NULL; j = j->next)
            if (strcmp(i->word, j->word) > 0)
                swap_elements(i, j);
}

int main()
{
    //Подготавливаем контейнер для считывания данных
    char input[INPUT_LEN];
    memset(input, 0, sizeof(input));

    //Считываем строку
    fgets(input, sizeof(input), stdin);

    //Убеждаемся, что на конце точка и перевод строки
    size_t len = strlen(input);
    if(len < 2 || input[len - 2] != '.' || input[len - 1] != '\n')
    {
        printf("Неожиданный формат строки");
        return -1;
    }

    //Очищаем последние два символа как служебные
    input[len - 1] = '\0';
    input[len - 2] = '\0';

    //Разбиваем на слова по пробелу и наполняем список
    char *token = strtok(input, " ");
    while(token != NULL)
    {
        add_to_list(token);
        token = strtok(NULL, " ");
    }

    //Сортируем список
    sort_list();

    //Выводим список
    print_list();

    //Очищаем список перед выходом
    delete_list();
}
