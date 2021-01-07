#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100


int sorted[MAX_SIZE];


void insertion_sort (int list[], int n);
void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);


int main()
{
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	// insertion_sort(list, n);

	for (i = 0; i < n; i++)
		printf("%d\n", list[i]);
}

// 인접한 원소끼리만 
void bubble_sort(int list[], int n)
{
	int i, j, temp;

	for (i = n - 1; i > 0; i--)
	{ // [i] 최고 값의 원소를 삽입 할 위치
		for (j = 0; j < i; j++)
		{ // [j] 비교 원소 
			if (list[j] > list[j + 1])
			{ // [j]를 [j+1]원소와 비교 (큰 원소를 [j+1]로)
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
  
}

// 카드 펼쳐놓고 하나씩 맞추는 느낌
void insertion_sort (int list[], int n)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{ // key(옮길 원소) 설정 
		key = list[i];
    
		for (j = i - 1; j >= 0 && list[j] > key; j--)
    { // [j]가 key 보다 크면 [j+1]로 치우기
			list[j + 1] = list[j];
    }  
		list[j + 1] = key; // [j]가 key 보다 작으면 [j+1]에 key 넣기
	}
  
}

// 최솟값을 찾아서 선택한 자리에 넣음
void selection_sort(int list, int n)
{
  int i, j, least, temp;
  
  for(i = 0; i < n-1; i++)
  {
    least = i;    
    for(j = i+1; j<n; j++)
    {
      if(list[j] < list[least])
        least = j;
    }    
    if(i != least)
    {
      temp = list[i];
      list[i] = list[least];
      list[least] = temp;
    }
  }

}

 
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// 중간을 기준으로 두개의 배열로 나누고 각 원소 값들을 하나씩 비교해 가며 임시 배열로 정렬
	while (i <= mid && j <= right) // 하나의 배열의 원소가 모두 정렬될 때까지
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남은 배열의 원소들은 임시 배열로 그대로 옮기기
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 임시 배열에서 배열로 옮기기
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // Divide
		merge_sort(list, left, mid); // Conquer
		merge_sort(list, mid + 1, right); // Conquer
		merge(list, left, mid, right); // Combine
	}
}
