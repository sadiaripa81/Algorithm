#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj_list(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int queries;
    cin >> queries;

    while (queries--)
    {
        int x_node;
        cin >> x_node;

        if (adj_list[x_node].empty())
        {
            cout << -1 ;
        }

        vector<int> print_list;
        for (int x : adj_list[x_node])
            print_list.push_back(x);

        sort(print_list.rbegin(), print_list.rend());
        for (int x : print_list)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
