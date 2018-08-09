// 演示 __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__ 的使用
#include <stdio.h>
void testFunc(void){
    printf("File = %s\nLine = %d\nFunc = %s\nDate = %s\nTime = %s\n", 
        __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__);
}

int main(void)
{
    testFunc();
    printf("Line = %d\nFunc = %s\n", __LINE__, __FUNCTION__);;
    return 0;
}
