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
    }

    int queries;
    cin >> queries;

    while (queries--)
    {
        int src, dest;
        cin >> src >> dest;

        if (src == dest)
        {
            cout << "YES\n";
            continue;
        }
        bool found = false;

        for (int x : adj_list[src])
        {
            if (x == dest)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}