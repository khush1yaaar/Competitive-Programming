#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, windowSize;
vector<ll> arr;
multiset<ll> maxHalf;
multiset<ll> minHalf;
ll sum_minHalf, sum_maxHalf;

ll calculateMedian()
{
    if (windowSize % 2 == 0)
        return 0;
    return *minHalf.rbegin();
}

void adding(ll value)
{
    ll current_median = *minHalf.rbegin();
    if (current_median < value)
    {
        maxHalf.insert(value);
        sum_maxHalf += value;
        if (maxHalf.size() > windowSize / 2)
        {
            ll moving = *maxHalf.begin();
            minHalf.insert(moving);
            sum_minHalf += moving;
            maxHalf.erase(maxHalf.find(moving));
            sum_maxHalf -= moving;
        }
    }
    else
    {
        minHalf.insert(value);
        sum_minHalf += value;
        if (minHalf.size() > (windowSize + 1) / 2)
        {
            ll moving = *minHalf.rbegin();
            maxHalf.insert(moving);
            sum_maxHalf += moving;
            minHalf.erase(minHalf.find(moving));
            sum_minHalf -= moving;
        }
    }
}

void removing(ll value)
{
    if (maxHalf.find(value) != maxHalf.end())
    {
        maxHalf.erase(maxHalf.find(value));
        sum_maxHalf -= value;
    }
    else
    {
        minHalf.erase(minHalf.find(value));
        sum_minHalf -= value;
    }
    if (minHalf.empty())
    {
        ll moving = *maxHalf.begin();
        minHalf.insert(moving);
        sum_minHalf += moving;
        maxHalf.erase(maxHalf.find(moving));
        sum_maxHalf -= moving;
    }
}

int main()
{
    cin >> n >> windowSize;
    int i = 0;
    while (i < n)
    {
        int input;
        cin >> input;
        arr.push_back(input);
        i++;
    }
    minHalf.insert(arr[0]);
    sum_minHalf += arr[0];
    for (ll i = 1; i < windowSize; i++)
        adding(arr[i]);

    cout << sum_maxHalf - sum_minHalf + calculateMedian() << " ";

    for (ll i = windowSize; i < n; i++)
    {
        if (windowSize == 1)
        {
            adding(arr[i]);
            removing(arr[i - windowSize]);
        }
        else
        {
            removing(arr[i - windowSize]);
            adding(arr[i]);
        }
        cout << sum_maxHalf - sum_minHalf + calculateMedian() << " ";
    }
}