#include <bits/stdc++.h>
using namespace std;

#define pr pair<int, int>

float CalculateDistance(vector<vector<int>> a, vector<int> b)
{
    int n = a.size();
    int X = b[0], Y = b[1];

    vector<pr> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(a[i][0], a[i][1]));
    }
    sort(v.begin(), v.end());

    float ans = 0.0;
    ans += abs(v[0].second - v[1].second);
    int mx = 0;
    for (int i = 1; i < n; i += 3)
    {
        if (Y >= v[i].second && v[i].second >= mx)
        {
            ans += v[i + 1].first - v[i].first;
            mx = max(mx, v[i].second);
        }
    }
    mx = 0;
    for (int i = 5; i < n; i += 4)
    {
        if (i + 1 < n && v[i + 1].second >= mx && v[i + 1].second >= Y)
        {
            ans += abs(v[i + 1].second - v[i - 1].second);
            mx = max(mx, v[i + 1].second);
        }
    }
    mx = 0;
    for (int i = 5; i < n; i += 4)
    {
        if (i + 1 < n && v[i + 1].second >= mx && v[i + 1].second > v[i - 1].second)
        {
            float x, y;
            x = float(v[i - 1].first - X);
            y = float(v[i - 1].second - Y);
            int distance = v[i].first - v[i - 1].first;
            float slope = (y / x);

            ans += tan(slope) * distance;
            mx = max(mx, v[i + 1].second);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2, 0));
    vector<int> coordinates(2);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    cin >> coordinates[0] >> coordinates[1];
    float s = CalculateDistance(v, coordinates);

    cout << fixed << setprecision(1) << s << endl;
}