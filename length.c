#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *str = "Rob and Daven 4 ever";
	printf("string \" %s \" is %lu characters long.\n", str, strlen(str));
}