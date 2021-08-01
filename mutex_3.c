#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//锁
pthread_mutex_t lock;	

int val = 0;

void *MyFun( void *args)
{
	for( int ix = 0; ix < 10000; ++ix ){
		pthread_mutex_lock(&lock);
		++val;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main()
{
	pthread_t th1, th2;
	pthread_mutex_init(&lock, NULL);
	pthread_create( &th1, NULL, MyFun, NULL );
	pthread_create( &th2, NULL, MyFun, NULL );
	pthread_join(th1, NULL);
	pthread_join( th2, NULL );
	printf("val = %d\n", val);
	return 0;
}