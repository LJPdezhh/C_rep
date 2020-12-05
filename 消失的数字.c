#include<stdio.h>
#include<Windows.h>

int missingNumber(int* nums, int numsSize){
	int tem = 0;
	for (int i = 0; i<numsSize; i++){
		tem ^= i;//0和数组的下标异或
		tem ^= nums[i];//0和每个元素异或

	}
	tem ^= numsSize;//由于丢了一个元素，这一步是找出丢失的元素
	return tem;
}

int main()
{
	int arr[] = { 2, 4, 1, 3, 5 };
	int tem=missingNumber(arr, 5);
	printf("%d\n", tem);
	system("pause");
	return 0;
}