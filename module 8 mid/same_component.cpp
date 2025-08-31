#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool can_go = false;

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
void dfs(int si, int sj, int di, int dj)
{
    vis[si][sj] = true;

    if (si == di && sj == dj)
    {
        can_go = true;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj, di, dj);
            if (can_go == true)
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

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    if (si == -1 || sj == -1)
    {
        cout << "NO" << endl;
    }
    memset(vis, false, sizeof(vis));
    dfs(si, sj, di, dj);

    if (can_go == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}