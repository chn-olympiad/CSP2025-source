#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s[10005][2],t[10005][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> s[i][0] >> s[i][1];
    }
    for (int i=1;i<=q;i++)
    {
        cin >> t[i][0] >> t[i][1];
        for (int i=0;i<t[i][0].size();i++)
        {
            for (int j=i;j<t[i][0].size();j++)
            {
                string s1,s2;
                for (int k=i;k<=j;k++)
                {
                    s1+=t[i][0][k];
                    s2+=t[i][1][k];
                }
                for (int k=1;k<=n;k++)
                {
                    if (s1==s[i][0]&&s2==s[i][1])
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
