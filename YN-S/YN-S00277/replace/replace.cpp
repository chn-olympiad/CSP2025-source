#include <bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int n,q;
int solve(string s3,string s4)
{
    int len = s3.length(),ans = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= len - s1[i].length(); j++)
        {
            for (int k = 0; k < j; k++)
            {
                if(s3[k] != s4[k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
            for (int k = 0; k < s1[i].length(); k++) if(s1[i][k] != s3[k + j]) flag = false;break;
            if(flag == false) continue;
            for (int k = 0; k < s2[i].length(); k++) if(s2[i][k] != s4[k + j]) flag = false;break;
            if(flag == false) continue;
            for (int k = j + s1[i].length(); k < len; k++) if(s3[k] != s4[k - s1[i].length() + s2[i].length()]) flag = false;break;
            if(flag == true) ans++;
        }
    }
    return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
    }
    string s3,s4;
    for (int i = 1; i <= q; i++)
    {
        cin >> s3 >> s4;
        cout << solve(s3,s4) << endl;
    }
    return 0;
}
