#include <bits/stdc++.h>
using namespace std;
int f[15],cnt[5],a[12][5],g[15];
struct N
{
    int aa,bb,cc,diff;
}b[100005];
string its (int x,int y)
{
    string s="";
    while (x>0)
    {
        char c=(x%3)+'0';
        s=c+s;
        x/=3;
    }
    while (s.size()<y) s='0'+s;
    return s;
}
bool cmp(N x,N y)
{
    return x.diff>y.diff;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n>10)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>b[i].aa>>b[i].bb>>b[i].cc;
            }
            for(int i=1;i<=n;i++)
            {
                b[i].diff=b[i].aa-b[i].bb;
            }
            sort(b+1,b+n+1,cmp);
            long long ans=0;
            for(int i=1;i<=n/2;i++) ans+=b[i].aa;
            for(int i=n/2+1;i<=n;i++) ans+=b[i].bb;
            cout<<ans<<endl;
        }
        else
        {
            int anss=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=3;j++)
                {

                    cin>>a[i][j-1];
                }
            }
            for(int i=1;i<pow(3,n);i++)
            {
                for(int j=0;j<=2;j++) cnt[j]=0;
                string s=its(i,n);
                //cout<<s;
                for(int j=0;j<n;j++)
                {
                    cnt[s[j]-'0']++;
                }
                bool flag=1;
                for(int j=0;j<3;j++)
                {
                    if (cnt[j]>n/2)
                    {
                        flag=0;
                        break;
                    }
                }
                if (flag)
                {
                    int ans=0;
                    for(int j=1;j<=n;j++)
                    {
                        ans+=a[j][s[j-1]-'0'];
                    }
                    if (ans>anss)
                    {
                        for(int j=1;j<=n;j++) g[j]=s[j-1]-'0'+1;
                        anss=ans;
                    }
                }
            }
            cout<<anss<<endl;
        }

    }
    return 0;
}
