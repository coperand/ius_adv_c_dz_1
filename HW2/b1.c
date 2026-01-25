#include <stdio.h>
#include <stdint.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head)
{
    size_t total = 0;
    list *current = head;
    while(current != NULL)
    {
        total += current->size;
        current = current->next;
    }
    
    return total;
}
