#include <iostream>


int count_max(const int* arr, int size) {
	int max = 0,
		count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			count = 0;
		}
		if (arr[i] == max) {
			count++;
		}
	}

	std::cout << "Максимальное значение - " << max << " ";
	return count;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int  SIZE = 10;

	int A[SIZE] = { 1,5,2,6,3,8,9,9,7,8 };
	int B[SIZE] = { 1,15,2,15,3,15,9,15,7,8 };
	int C[SIZE] = { 1,15,100,100,100,100,100,15,7,8 };

	int newSize;
	std::cout << "Введите размер массива - ";
	std::cin >> newSize;
	int* D = new int[newSize];

	std::cout << "Динамический массив - ";
	for (int i = 0; i < newSize; i++) {
		D[i] = rand() % 16 - 5;
		std::cout << D[i] << " ";
	}

	std::cout << "\n";
	std::cout << "Количество повторений - " << count_max(A, SIZE) << "\n";
	std::cout << "Количество повторений - " << count_max(B, SIZE) << "\n";
	std::cout << "Количество повторений - " << count_max(C, SIZE) << "\n";
	std::cout << "Количество повторений - " << count_max(D, newSize) << "\n";

	delete[] D;
}