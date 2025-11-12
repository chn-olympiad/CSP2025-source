#include<bits/stdc++.h>
using LL = long long;
using namespace std;

int n,q;
string s[1005][3];
int l[1005];
string t1,t2,tc;
int ds[2010];

int main()
{
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    cin >>n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> s[i][1] >> s[i][2];
        l[i] = s[i][1].size();
    }
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> t1 >> t2;
        int l1 = t1.size();
        int l2 = t2.size();
        if(l1 != l2)
        {
            printf("0\n");
            continue;
        }
        int cntd = 0;
        for(int i = 0 ; i <= l1-1 ; i++)
        {
            if(t1[i] != t2[i])
            {
                ds[++cntd] = i;
            }

        }
        int dl = ds[cntd] - ds[1]+1;
        int cnt = 0;
        for(int it = 0 ; it <= l1-1 ; it++)
        {
            if(it!=0 && t1[it-1] != t2[it-1]) break;
            for(int j = 1 ; j <= n ; j++)
            {
                if(l[j] < dl)continue;
                if(t1[it] == s[j][1][0] && t2[it] == s[j][2][0])
                {
                    for(int is = 0 ; is <= l[j]-1 ; is++)
                    {
                        if(t1[it+is] != s[j][1][is] || t2[it+is] != s[j][2][is]) break;
                        if(is == l[j]-1)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
