#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double maxProfit = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity)
        {

            capacity -= items[i].weight;
            maxProfit += items[i].profit;
            cout << "Item " << i + 1 << " taken completely with profit " << items[i].profit << " and weight " << items[i].weight << endl;
        }
        else
        {

            double fraction = (double)capacity / items[i].weight;
            maxProfit += items[i].profit * fraction;
            cout << "Item " << i + 1 << " taken partially with profit " << items[i].profit * fraction << " and weight " << capacity << endl;
            capacity = 0;
        }
    }

    return maxProfit;
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    double maxProfit = fractionalKnapsack(capacity, items);
    cout << "Maximum profit (Fractional) for the knapsack: " << maxProfit << endl;

    return 0;
}
