#include <stdint.h>
#include <stdio.h>
int main()
{
    // uint32_t *ptr;
    // uint32_t num;
    // *(uint32_t *)(ptr + num);
    uint32_t arr[] = {1, 3, 5, 7, 9};
    uint32_t *ptr = arr;
    uint32_t num = 2;

    printf("%u\n", *(ptr + num));
    return 0;
}
