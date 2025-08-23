#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int si, sj;
bool found_B = false;

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
void dfs(int si, int sj)
{
    vis[si][sj] = true;

    if (grid[si][sj] == 'B')
    {
        found_B = true;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
        {
            dfs(ci, cj);
            if (found_B == true)
            {
                return;
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
        }

    if (si == -1 || sj == -1)
    {
        cout << "NO" << endl;
    }
    memset(vis, false, sizeof(vis));
    dfs(si, sj);

    if (found_B == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}