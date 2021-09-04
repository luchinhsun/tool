#include <stdio.h>

#define detail 0

int main(){

	char array [6] = { 5, 11, 7, 4, 2, 6 };
	char *p = &array[0];
	printf("array = {5,11,7,4,2,6}\n");
        printf("p=&array[0]\n");
	if (detail){
		printf("*p=%d\n", *p);
		printf("++*p %d\n", ++*p);
		printf("*p=%d\n", *p);
		printf("++(*p) %d\n", ++(*p));
		printf("*p=%d\n", *p);
		printf("++*(p) %d\n", ++*(p));
		printf("*p=%d\n", *p);
		printf("(*p)++ %d\n", (*p)++);
		printf("*p=%d\n", *p);
		printf("*(p)++ %d\n", *(p)++);
		printf("*p=%d\n", *p);
		printf("*++p %d\n", *++p);
		printf("*p=%d\n", *p);
		printf("*(++p) %d\n", *(++p));
		printf("*p=%d\n", *p);
	}else{
		printf("++*p %d\n", ++*p);
                printf("++(*p) %d\n", ++(*p));
                printf("++*(p) %d\n", ++*(p));
                printf("(*p)++ %d\n", (*p)++);
                printf("*(p)++ %d\n", *(p)++);
                printf("*++p %d\n", *++p);
                printf("*(++p) %d\n", *(++p));
	}
}
