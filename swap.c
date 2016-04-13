/* 使用指针进行交换操作 */
#include <stdio.h>
void interchange(int * u, int * v);

/*
int main(void)
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(&x, &y);    //向函数传递地址
    printf("Now x = %d and y = %d.\n", x, y);
    return 0;
}
*/

void interchange(int * u, int * v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}