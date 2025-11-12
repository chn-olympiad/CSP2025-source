#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+27;
constexpr int maxm=5e6+13;
constexpr int inf=(LLONG_MAX>>1)-1;

int n,q;
string s[maxn][3];
int len[maxn];
string t1,t2;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i][1]>>s[i][2];
        len[i]=s[i][1].size();
    }
    while(q--)
    {
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<"0\n";
            continue;
        }
        int str=-1;
        int en=0;
        int m=t1.size();
        for(int i=0;i<m;++i)
        {
            if(t1[i]!=t2[i])
            {
                if(str==-1)
                {
                    str=i;
                }
                en=max(en,i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(len[i]<en-str+1)
            {
                continue;
            }
            for(int j=max(0LL,en-len[i]+1);j<min(m-len[i]+1,str+1);++j)
            {
                bool o=1;
                for(int l=0;l<len[i];++l)
                {
                    if(t1[j+l]!=s[i][1][l])
                    {
                        o=0;
                        break;
                    }
                }
                if(o==1&&j+len[i]>=en)
                {
                    for(int l=j;l<j+len[i];++l)
                    {
                        if(t2[l]!=s[i][2][l-j])
                        {
                            o=0;
                            break;
                        }
                    }
                    if(o==1)
                    {
                        ++ans;
                    }
                    //cout<<b<<endl;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}

