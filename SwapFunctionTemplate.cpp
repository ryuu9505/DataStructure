#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

template <typename T>
void Swap(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 1, b = 2;

	Swap<int>(&a, &b);

	printf("%d %d", a, b);
}
