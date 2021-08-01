#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//定义一个结构体来传递输入，输出参数
typedef struct
{
	int begin;
	int end;
	int result;
} ARGS;

const int ARR_LEN = 1000;
int arr[1000];

void* myFun( void *args)
{
	ARGS *in = (ARGS*)args;
	int begin = in->begin, end = in->end;
	int sum = 0;
	for( int ix = begin; ix < end; ++ix ){
		sum += arr[ix];
	}
	in->result = sum;
	return NULL;
}


//当需要向线程中传入输入输出参数时
//eg : 使用两个线程进行数组求和
int main()
{
	//初始化数组
	for( int ix = 0; ix < ARR_LEN; ++ix ){
		arr[ix] = rand() % 10;
 	}
 	ARGS arg1 = {0, 500, 0}, arg2 = {500, 1000, 0};
	pthread_t th1, th2;
	pthread_create( &th1, NULL, myFun, &arg1 );
	pthread_create( &th2, NULL, myFun, &arg2 );
	pthread_join( th1, NULL );
	pthread_join( th2, NULL );
 	printf("sum1 = %d, sum2 = %d, sum = %d\n", arg1.result, arg2.result, arg1.result+arg2.result);
	
	return 0;
}