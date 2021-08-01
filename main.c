#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//线程入口函数
void  *myFunc(void *args)
{
	char *threadName = (char*)args;
	for( int ix = 0; ix < 500; ++ix ){
		printf("%s : %d\n", threadName,  ix);
	}
	return NULL;
}

//compile: gcc main.c -lpthread -o main
int main( int argc, char **argv )
{
	pthread_t th1, th2;
	pthread_create(&th1, NULL, myFunc, "th1");
	pthread_create(&th2, NULL, myFunc, "th2");
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	
	return 0;
}

//线程入口函数