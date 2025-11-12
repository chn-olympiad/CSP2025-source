#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,q,tot;
int posl[N],posr[N];
string s1[N],s2[N],c[N],d[N],t1,t2,tc,td;
string pre[N],suf[N],tp,ts;
void getdiff(string s1,string s2,int &posl,int &posr)
{
    posl=-1,posr=-1;
    for(int j=0;j<s1.size();j++)
    {
        if(s1[j]!=s2[j])
        {
            if(posl==-1) posl=j;
            posr=j;
        }
    }
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        getdiff(s1[i],s2[i],posl[i],posr[i]);
        if(posl[i]==-1)
        {
            c[i]="!";
            continue;
        }
        c[i]=s1[i].substr(posl[i],posr[i]-posl[i]+1);
        d[i]=s2[i].substr(posl[i],posr[i]-posl[i]+1);
        pre[i]=s1[i].substr(0,posl[i]);
        suf[i]=s1[i].substr(posr[i]+1,s1[i].size()-posr[i]-1);
    }
    while(q--)
    {
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<"0\n";
            continue;
        }
        int pol=-1,por=-1,ans=0;
        getdiff(t1,t2,pol,por);
        tc=t1.substr(pol,por-pol+1);
        td=t2.substr(pol,por-pol+1);
        tp=t1.substr(0,pol);
        ts=t1.substr(por+1,t1.size()-por-1);
        for(int i=1;i<=n;i++)
        {
            if(tc==c[i]&&td==d[i])
            {
                bool flag=1;
                if(tp.size()>=pre[i].size())
                {
                    for(int j=0;j<pre[i].size();j++)
                    {
                        if(tp[tp.size()-j-1]!=pre[i][pre[i].size()-j-1])
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                else flag=0;
                if(ts.size()>=suf[i].size())
                {
                    for(int j=0;j<suf[i].size();j++)
                    {
                        if(ts[j]!=suf[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                else flag=0;
                if(flag) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
4 1
x y
ax ay
xa ya
axa aya
axa aya
*/