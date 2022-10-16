#include <iostream>
#include <fstream>

int countString(int** arr, int N, int M) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j+1] == arr[i][j]) {
                ++count;
                break;
            }
        }
    }
    count = N - count;
    return count;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, m;

    std::ifstream in("infile.txt");

    if (!in.is_open())
    {
        std::cerr << "Файл не может быть открыт \n";
        return 1;
    }

 while(!in.eof()){

    in >> n >> m;

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
        for (int j = 0; j < m; j++)
            in >> A[i][j];
    }

    std::cout << "Матрица: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "Количество строк, в которых нет подряд идущих повторяющихся элементов - " << countString(A, n, m);
    std::cout << '\n';

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

}
        in.close();
        return 0;
    

}