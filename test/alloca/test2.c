#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include<unistd.h>
#include<string.h>

#define	NUM		1

int main(int argc, char** argv)
{
	int len[] = {-32};
	char *buf[NUM];
	int ii;
	
	printf("start\n\n");
	
	for( ii = 0; ii < sizeof(len) / sizeof(int); ii++ )
	{
		printf("ii=%d\n", ii);
		
		buf[ii] = alloca(len[ii]);
		printf("buf[%d] = %p\n", ii, buf[ii]);
		
		buf[ii][0] = ii;
		printf("buf[%d][0]  = 0x%x\n", ii, buf[ii][0]);
		printf("&buf[%d][0] = %p\n\n", ii, &buf[ii][0]);
	}
	
	printf("pass\n");
	
	return(0);
}
