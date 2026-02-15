#include <stdio.h>
#include <stdlib.h>

//Максимальное количество узлов
#define MAX_NODES 1000

void btUpView(tree *root)
{
    //Если дерево пустое, ничего печатать не нужно
    if(!root)
        return;

    //Максимальный размер вспомогательных массивов
    int max_nodes = MAX_NODES;

    //Выделяем память под массив указателей на узлы (очередь через кольцевой буфер)
    tree **queue = (tree**)malloc(max_nodes * sizeof(tree*));
    if(!queue)
        return;

    //Выделяем память под массив горизонтальных расстояний для соответствующих элементов очереди
    int *horizontal_distances = (int*)malloc(max_nodes * sizeof(int));
    if(!horizontal_distances)
    {
        free(queue);
        return;
    }

    //Таблица "увиденных" горизонтальных расстояний и значения для них
    int *seen = (int*)malloc(max_nodes * sizeof(int));
    if(!seen)
    {
        free(queue);
        free(horizontal_distances);
        free(seen);
        return;
    }
    int *vals = (int*)malloc(max_nodes * sizeof(int));
    if(!vals)
    {
        free(queue);
        free(horizontal_distances);
        free(seen);
        free(vals);
        return;
    }

    //Инициализируем массив seen нулями
    for(int i = 0; i < max_nodes; ++i)
        seen[i] = 0;

    //Инициализируем указателb кольцевой очереди (head — где брать, tail — куда класть)
    int head = 0, tail = 0;

    //Кладём корень в очередь
    queue[tail] = root;
    horizontal_distances[tail] = 0;
    tail = (tail + 1) % max_nodes;

    //Выбираем центр массива как смещение
    int offset = max_nodes / 2;

    //Переменные для отслеживания наименьшего и наибольшего встреченного расстояния
    int hd_min = 0, hd_max = 0;

    //Перебираем элементы, пока очередь не пуста
    while(head != tail)
    {
        //Берём текущий элемент из очереди
        tree *n = queue[head];
        int hd = horizontal_distances[head];
        head = (head + 1) % max_nodes;

        //Если индекс в пределах таблицы и для этого HD ещё не записано значение
        int idx = hd + offset;
        if(idx >= 0 && idx < max_nodes && !seen[idx])
        {
            //Помечаем значение и факт обработки элемента
            seen[idx] = 1;
            vals[idx] = *((datatype*)&n->key);

            //Обновляем границы встреченных HD
            if(hd < hd_min)
                hd_min = hd;
            if(hd > hd_max)
                hd_max = hd;
        }

        //Рассчитываем следующий свободный индекс
        int next_tail = (tail + 1) % max_nodes;

        //Если есть левый ребёнок, ставим в очередь с hd-1
        if(n->left)
        {
            //Если очередь полна, рекращаем обработку
            if(next_tail == head)
                break;

            //Добавляем ребёнка в очередь
            queue[tail] = n->left;
            horizontal_distances[tail] = hd - 1;
            tail = next_tail;
            next_tail = (tail + 1) % max_nodes;
        }

        //Если есть правый ребёнок, ставим в очередь с hd+1
        if(n->right)
        {
            //Если очередь полна, рекращаем обработку
            if(next_tail == head)
                break;

            //Добавляем ребёнка в очередь
            queue[tail] = n->right;
            horizontal_distances[tail] = hd + 1;
            tail = next_tail;
        }
    }

    //Печатаем результаты — от минимального до максимального расстояния (слева направо)
    for(int h = hd_min; h <= hd_max; ++h)
    {
        int i = h + offset;
        if(i >= 0 && i < max_nodes && seen[i])
        {
            //Печатаем пробел перед каждым элементом, кроме первого
            if (h != hd_min)
                printf(" ");
            //Выводим сам элемент
            printf("%d", vals[i]);
        }
    }
    //В конце переводим строку
    printf("\n");

    //Освобождаем выделенную память
    free(queue);
    free(horizontal_distances);
    free(seen);
    free(vals);
}
