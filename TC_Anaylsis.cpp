#include <iostream>
#include <cmath>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include <unordered_map>
#include <numeric>
using namespace std;

vector<int> generate(int size)
{
    vector<int> ele;
    for (int x = 1; x <= size; x++)
    {
        ele.push_back(rand());
    }

    return ele;
}
void sum(vector<int> arr)
{
    long long sum_num = 0;
    for (auto i : arr)
    {
        sum_num += i;
    }
}
void sel_sort(vector<int> arr)
{
    int mini = INT_MAX;
    int idx = 0;
    for (int x = 0; x < arr.size(); x++)
    {

        idx = x;
        mini = arr[x];
        for (int f = x + 1; f < arr.size(); f++)
        {
            if (arr[f] <= mini)
            {
                idx = f;
                mini = arr[f];
            }
        }
        swap(arr[idx], arr[x]);
    }
}
void permute(vector<int> arr, vector<int> ele, int idx)
{
    if (ele.size() == arr.size())
    {
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[i], arr[idx]);
        permute(arr, ele, idx + 1);
        swap(arr[i], arr[idx]);
    }
}
void hanoi()
{
}

void solve()
{
    vector<pair<int, double>> time;
    double avg = 0;
    for (int x = 6; x <= 10; x += 2)
    {

        vector<int> arr = generate(x);
        int cnt = 10;
        for (int f = 0; f < 10; f++)
        {
            clock_t start = clock();
            // sel_sort(arr);
            // sum(arr);
            permute(arr, {}, 0);
            clock_t end = clock();
            avg += (end - start);
        }
        time.push_back({x, (double)(avg) / double(cnt)});
    }
    for (auto i : time)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{

    // int t;
    // cin >> t;

    solve();
}
