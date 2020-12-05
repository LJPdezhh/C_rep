/**
* Note: The returned array must be malloced, assume caller calls free().
*/

//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

//找出这两个只出现一次数字的函数
int* singleNumbers(int* nums, int numsSize, int* returnSize){
	*returnSize = 2;
	int XorRes = 0;//异或结果存在XorRes中
	int *arr = (int *)malloc(2 * sizeof(int));//为最终的结果申请内存
	memset(arr, 0, 2 * sizeof(int));//存放结果的空间初始化
	//求出所有数异或之后的结果
	for (int i = 0; i < numsSize; i++){
		XorRes ^= nums[i];
	}
	//利用异或结果的相反数的补码 和  异或的结果 异或，得到二进制中从右往左数，
	//（接上）第一个位置为1，其他位置为0的二进制数。
	XorRes = XorRes&((-1)*XorRes);
	//利用上面找到的数，继续与所有数异或，会将两个出现一次的数分为两类，即找到
	for (int i = 0; i < numsSize; i++){
		if ((nums[i] & XorRes) == 0){
			arr[0] ^= nums[i];
		}
		else{
			arr[1] ^= nums[i];
		}
	}
	printf("%d  %d\n", arr[0], arr[1]);
}
int main(){
	int arr[] = { 1, 2, 2, 3, 3, 4, 4, 5 };
	int arr1[] = { 0 };
	singleNumbers(arr, 8, arr1);
	system("pause");
	return 0;
}

