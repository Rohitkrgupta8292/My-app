//bubble sorting.
#include <iostream>
using namespace std;
// function to sort array in acsending order from bubble sort..//
void bubbleSort(int a[], int n)
{
	int sorted = 0;
    for(int i=0; i<n-1; i++)
    {
    	sorted = 1;
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                sorted = 0;
            }
        }
        if(sorted)
        {
           return;
        }
    }
}
// function to print sorted array..//
void print(int a[],int n)
{
	cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
	int a[] = {21,3,45,64,31};
	int n = 5;
    // calling soritng & printing function for array..//
    bubbleSort(a, n); // bubble sort algorithm..//
    print(a, n); //printing array..//
    return 0;
}