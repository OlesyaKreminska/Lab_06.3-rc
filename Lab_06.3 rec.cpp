#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
void Inverse(int* a, const int n, int i)
{
    int tmp = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = tmp;
    if (i < n / 2 - 1)
        Inverse(a, n, i + 1);
}

template <typename T>
void SecondCreate(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

template <typename T>
void SecondPrint(T* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
void SecondInverse(T* a, const int n, int i)
{
    T tmp = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = tmp;
    if (i < n / 2 - 1)
        Inverse(a, n, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 9;
    int a[n];
    int Low = -10;
    int High = 10;
    Create(a, n, Low, High, 0);
    Print(a, n, 0);
    Inverse(a, n, 0);
    Print(a, n, 0);

    const int size = 9;
    double b[size];
    double low = -10;
    double high = 10;
    SecondCreate(a, size, Low, High, 0);
    SecondPrint(a, size, 0);
    SecondInverse(a, size, 0);
    SecondPrint(a, size, 0);
    return 0;
}
