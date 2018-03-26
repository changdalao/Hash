#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct BitMap
{
	size_t* _bits;
	size_t range;//范围
}BitMap;
void BitMapInit(BitMap* bm, size_t range)
{
	bm->range = range;
	bm->_bits = (size_t*)malloc(sizeof(size_t)*(range / 32 + 1));
	memset(bm->_bits, 0, sizeof(size_t)*(range / 32 + 1));
}
void BitMapSet(BitMap* bm,size_t x)
{ 
	size_t index = x / 32;//第几个数
	size_t num = x % 32;//第几个位
	bm->_bits[index] |= (1 << num);
}
void BitMapRset(BitMap* bm, size_t x)
{
	size_t index = x / 32;
	size_t num = x % 32;
	bm->_bits[index] &= (~(1 << num));
}
int BitMapTest(BitMap* bm, size_t x)
{
	size_t index = x / 32;
	size_t num = x % 32;
	if (bm->_bits[index] & (1 << num))//存在返回0
		return 0;
	else 
		return -1;
}
void TestBitMap()
{
	BitMap bm;
	BitMapInit(&bm, -1);
	BitMapSet(&bm, 1);
	BitMapSet(&bm, 8);
	BitMapSet(&bm, 10000);
	BitMapSet(&bm, 1000111111);

	printf("10000?%d\n",BitMapTest(&bm,10000));
	printf("1000111111?%d\n", BitMapTest(&bm, 1000111111));
	printf("10?%d\n", BitMapTest(&bm, 10));

	BitMapRset(&bm, 1000111111);
	printf("10000?%d\n", BitMapTest(&bm, 10000));
	printf("1000111111?%d\n", BitMapTest(&bm, 1000111111));
	printf("10?%d\n", BitMapTest(&bm, 10));

}
