#include <stdio.h>

void main(void)
{
    /* 整数的十进制、八进制、十六进程输出 */
    int x= 100;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
    
    /* 整数溢出，从达到最大值时，将溢出到起始点 */
    int i = 2147483647;
    unsigned int j = 4294967295;
    
    printf("%d %d %d \n", i, i + 1, i + 2);
    printf("%u %u %u \n", j, j + 1, j + 2);
    
    /* 字符显示 */
    //printf("\a");    
    //printf("hello!\007\n");
    
    char ch = 'C';
    printf("The code for %c is %d.\n", ch, ch);
}
