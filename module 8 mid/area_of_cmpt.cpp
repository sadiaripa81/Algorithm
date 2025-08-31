#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {

            cnt += dfs(ci, cj);
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    vector<int> components;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == '.')
            {
                int room = dfs(i, j);
                components.push_back(room);
            }
        }
    }

    sort(components.begin(), components.end());
    int min_components = components.front();

    if (components.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_components << " ";
    }
    return 0;
}