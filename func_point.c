#include <stdio.h>
 
#define  GET_MAX 	0
#define  GET_MIN 	1
 
int get_max(int i,int j)
{
	return i>j?i:j;
}
 
int get_min(int i,int j)
{
	return i>j?j:i;
}
 
int compare(int i,int j,int flag)
{
	int ret;
 
	//这里定义了一个函数指针，就可以根据传入的flag，灵活地决定其是指向求大数或求小数的函数
	//便于方便灵活地调用各类函数
	int (*p)(int,int);
 
	if(flag == GET_MAX)
		p = get_max;
	else
		p = get_min;
 
	ret = p(i,j);
 
	return ret;
}
 
int main()
{
	int i = 5,j = 10,ret;
 
	ret = compare(i,j,GET_MAX);
	printf("The MAX is %d\n",ret);
 
	ret = compare(i,j,GET_MIN);
	printf("The MIN is %d\n",ret);
 
	return 0 ;
}

