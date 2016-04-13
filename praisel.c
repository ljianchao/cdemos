/* 使用不同类别的字符串 */
#include <stdio.h>
#include <string.h>
#define PRAISE "What a super marvlous name!"    //定义常量

void main(void)
{
    char name[40];
    
    printf("What's your name?\n");
    scanf("%s", name);
    printf("hello, %s, %s\n", name, PRAISE);
    printf("Your name of %d letters occupies %d memory cells.\n",
            strlen(name), sizeof name);
            
    printf("The phrase of praise has %d letters", strlen(PRAISE));
    printf(" and occupies %d memory cells.\n", sizeof PRAISE);
}