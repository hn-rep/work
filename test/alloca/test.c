#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char** argv)
{
	int len[5] = {16, 1, 0, -1, -16};
	char *buf[5];
	int ii;
	
	printf("start\n\n");
	
	for( ii = 0; ii < sizeof(len) / sizeof(int); ii++ )
	{
		buf[ii] = alloca(len[ii]);
		printf("buf[%d] = %p\n", ii, buf[ii]);
		
		buf[ii][0] = ii;
		printf("buf[%d][0]  = 0x%x\n", ii, buf[ii][0]);
		printf("&buf[%d][0] = %p\n\n", ii, &buf[ii][0]);
	}
	
	{
		printf("buf[3][0]  = 0x%x\n", buf[3][0]);
		printf("&buf[3][0] = %p\n\n", &buf[3][0]);
		
		printf("buf[4][0]  = 0x%x\n", buf[4][0]);
		printf("&buf[4][0] = %p\n\n", &buf[4][0]);
	}
	
	printf("pass\n");
	
	return(0);
}
