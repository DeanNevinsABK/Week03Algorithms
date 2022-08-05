#include <chrono>
#include <time.h>
#include <iostream>

using namespace std;

uint32_t GetNanos();

int testArray1[10];
int testArray2[100];
int testArray3[1000];
void FillArray(int arrayToFill[], int size);
void PrintArray(int arrayToPrint[], int size);
void BubbleSort(int arrayToSort[], int size);
void TestSort(int arrayToTest[], int size);

int main()
{
    srand(time(0));
    
    TestSort(testArray1, 10);
    TestSort(testArray1, 100);
    TestSort(testArray1, 1000);
    
}

void TestSort(int arrayToTest[], int size)
{
    FillArray(arrayToTest, size);
    cout << "\nUnordered List:\n";
    PrintArray(arrayToTest, size);
    uint32_t startNanos = GetNanos();
    BubbleSort(arrayToTest, size);
    uint32_t endNanos = GetNanos();
    cout << "\nOrdered List:\n";
    PrintArray(arrayToTest, size);
    cout << "Bubble Sort took: " << (endNanos - startNanos) << "ns \n\n";
}

uint32_t GetNanos()
{
    using namespace std::chrono;
    return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}

void FillArray(int arrayToFill[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arrayToFill[i] = rand() % size + 1;
    }
}

void PrintArray(int arrayToPrint[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arrayToPrint[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int arrayToSort[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arrayToSort[i] > arrayToSort[i + 1])
            {
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i + 1];
                arrayToSort[i + 1] = temp;
            }
        }
    }
}