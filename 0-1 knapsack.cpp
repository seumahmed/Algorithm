#include <iostream>
#include <vector>
using namespace std;


int max(int a, int b)
{
    return (a > b) ? a : b;
    }

int knapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);


    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}


int main()
{
    int value[] = {10, 5, 15, 7};
    int weight[] = {2, 3, 5, 7};
    int W = 10;
    int n = sizeof(value) / sizeof(value[0]);
    cout << "Maximum value that can be obtained: " << knapSack(W, weight, value, n) <<endl;

    return 0;
}


