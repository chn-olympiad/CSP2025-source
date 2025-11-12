#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
const int N = 2e5 + 10;
int n, q;
string s[N][2];
string t[N][2];

u64 power(u64 a, u64 b)
{
    u64 res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    using val_t = pair<string, string>;
    vector<val_t> sss;
    cin >> n >> q;
    map<val_t, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
        vector<u64> sum1(s[i][0].size() + 2, 0), sum2(s[i][0].size() + 2, 0), sum3(s[i][1].size() + 2, 0), sum4(s[i][1].size() + 2, 0);
        sum1[0] = s[i][0][0] - 'a', sum3[0] = s[i][1][0] - 'a';
        for (int j = 1; j < s[i][0].size(); j++)
        {
            sum1[j] = sum1[j - 1] + (s[i][0][j] - 'a') * power(11, j);
        }
        for (int j = 1; j < s[i][0].size(); j++)
        {
            sum3[j] = sum3[j - 1] + (s[i][1][j] - 'a') * power(11, j);
        }
        for (int j = s[i][0].size() - 1, k = 0; j >= 0; j--, k++)
        {
            sum2[j] = sum2[j + 1] + (s[i][0][j] - 'a') * power(11, k);
        }
        for (int j = s[i][1].size() - 1, k = 0; j >= 0; j--, k++)
        {
            sum4[j] = sum4[j + 1] + (s[i][1][j] - 'a') * power(11, k);
        }
        int x = -1, y = -1;
        for (int j = 0; j < s[i][0].size(); j++)
        {
            if (sum1[j] != sum3[j])
            {
                x = j;
                break;
            }
        }
        for (int j = s[i][1].size() - 1; j >= 0; j--)
        {
            if (sum2[j] != sum4[j])
            {
                y = j;
                break;
            }
        }
        string tmp1, tmp2;
        if (x != -1 && y != -1)
        {
            
            for (int j = x; j <= y; j++)
            {
                tmp1 += s[i][0][j];
                tmp2 += s[i][1][j];
            }
        }
        mp[{tmp1, tmp2}].push_back(i);
    }
    int i = n + 1;
    while (q--)
    {
        cin >> s[i][0] >> s[i][1];
        if (s[i][0].size() != s[i][1].size())
        {
            cout << "0" << endl;
            continue;
        }
        vector<u64> sum1(s[i][0].size() + 2, 0), sum2(s[i][0].size() + 2, 0), sum3(s[i][1].size() + 2, 0), sum4(s[i][1].size() + 2, 0);
        sum1[0] = s[i][0][0] - 'a', sum3[0] = s[i][1][0] - 'a';
        for (int j = 1; j < s[i][0].size(); j++)
        {
            sum1[j] = sum1[j - 1] + (s[i][0][j] - 'a') * power(11, j);
        }
        for (int j = 1; j < s[i][0].size(); j++)
        {
            sum3[j] = sum3[j - 1] + (s[i][1][j] - 'a') * power(11, j);
        }
        for (int j = s[i][0].size() - 1, k = 0; j >= 0; j--, k++)
        {
            sum2[j] = sum2[j + 1] + (s[i][0][j] - 'a') * power(11, k);
        }
        for (int j = s[i][1].size() - 1, k = 0; j >= 0; j--, k++)
        {
            sum4[j] = sum4[j + 1] + (s[i][1][j] - 'a') * power(11, k);
        }
        int x = -1, y = -1;
        for (int j = 0; j < s[i][0].size(); j++)
        {
            if (sum1[j] != sum3[j])
            {
                x = j;
                break;
            }
        }
        for (int j = s[i][1].size() - 1; j >= 0; j--)
        {
            if (sum2[j] != sum4[j])
            {
                y = j;
                break;
            }
        }
        string tmp1, tmp2;
        if (x != -1 && y != -1)
        {
            
            for (int j = x; j <= y; j++)
            {
                tmp1 += s[i][0][j];
                tmp2 += s[i][1][j];
            }
        }
        u64 cnt = 0;
        for (auto v : mp[{tmp1, tmp2}])
        {
            string str = s[v][0];
            if (s[i][0].find(str) <= s[i][0].size())
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}