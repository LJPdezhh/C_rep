#include<stdio.h>
#include<Windows.h>

int missingNumber(int* nums, int numsSize){
	int tem = 0;
	for (int i = 0; i<numsSize; i++){
		tem ^= i;//0��������±����
		tem ^= nums[i];//0��ÿ��Ԫ�����

	}
	tem ^= numsSize;//���ڶ���һ��Ԫ�أ���һ�����ҳ���ʧ��Ԫ��
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