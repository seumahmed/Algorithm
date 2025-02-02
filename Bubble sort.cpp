#include <iostream>
using namespace std;

int swp=0;
int compare=0;


void bubblesort(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int curr=0; curr<(n-1)-i; curr++)
        {
            if(arr[curr]>arr[curr+1])
            {
                int temp;
                temp=arr[curr];
                arr[curr]=arr[curr+1];
                arr[curr+1]=temp;
                swp++;
            }
            compare++;
        }
    }

}

int main()
{
    int arr[5]= {5,4,3,2,1};
    int n=sizeof(arr)/sizeof(int);

    cout<<"Given Array:";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";

    }

    bubblesort(arr,n);

    cout<<endl<<"Sorted Array:";

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nCompare: "<<compare<<"\nSwap: "<<swp;
}
