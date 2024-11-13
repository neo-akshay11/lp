#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, vector<int> &weights, vector<int> &profits, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            // table dp[i][w] to store the maximum profit for the first i items with a capacity w.
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], profits[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n), profits(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> profits[i] >> weights[i];
    }

    int maxProfit = knapsack(capacity, weights, profits, n);
    cout << "Maximum profit for the 0/1 knapsack: " << maxProfit << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int knapsack(int capacity, vector<int> &weights, vector<int> &profits, int n)
// {
//     vector<int> dp(capacity + 1, 0);

//     for (int i = 0; i < n; i++)
//     {
//         for (int w = capacity; w >= weights[i]; w--)
//         {
//             dp[w] = max(dp[w], profits[i] + dp[w - weights[i]]);
//         }
//     }

//     return dp[capacity];
// }

// int main()
// {
//     int n, capacity;
//     cout << "Enter the number of items: ";
//     cin >> n;
//     cout << "Enter the capacity of the knapsack: ";
//     cin >> capacity;

//     vector<int> weights(n), profits(n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter profit and weight for item " << i + 1 << ": ";
//         cin >> profits[i] >> weights[i];
//     }

//     int maxProfit = knapsack(capacity, weights, profits, n);
//     cout << "Maximum profit for the 0/1 knapsack: " << maxProfit << endl;

//     return 0;
// }
