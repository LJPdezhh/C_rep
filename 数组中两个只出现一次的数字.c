/**
* Note: The returned array must be malloced, assume caller calls free().
*/

//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

//�ҳ�������ֻ����һ�����ֵĺ���
int* singleNumbers(int* nums, int numsSize, int* returnSize){
	*returnSize = 2;
	int XorRes = 0;//���������XorRes��
	int *arr = (int *)malloc(2 * sizeof(int));//Ϊ���յĽ�������ڴ�
	memset(arr, 0, 2 * sizeof(int));//��Ž���Ŀռ��ʼ��
	//������������֮��Ľ��
	for (int i = 0; i < numsSize; i++){
		XorRes ^= nums[i];
	}
	//������������෴���Ĳ��� ��  ���Ľ�� ��򣬵õ��������д�����������
	//�����ϣ���һ��λ��Ϊ1������λ��Ϊ0�Ķ���������
	XorRes = XorRes&((-1)*XorRes);
	//���������ҵ���������������������򣬻Ὣ��������һ�ε�����Ϊ���࣬���ҵ�
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

