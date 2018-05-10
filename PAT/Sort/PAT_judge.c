#include <stdio.h>
#include <stdlib.h>

#define Maxuser 10000

struct UNode
{
	int total_score;
	int Score[5];
	int flag;
};

int main(int argc, char const *argv[])
{
	struct UNode x={1,{-1,},0};
	printf("%d\n", x.Score[2]);
	return 0;
}