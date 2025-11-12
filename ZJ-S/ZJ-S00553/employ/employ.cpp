#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int maxn=5e2+10;
constexpr int MOD=998244535;
char s[maxn];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf(" %s",s);
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]&1)
        {
            ++cnt;
        }
    }
    cerr<<cnt<<endl;
    vector<int> p(n);
    for(int &i:p)
    {
        scanf("%d",&i);
    }
    sort(p.begin(),p.end());
    int res=0;
    do
    {
        for(int i=0;i<1<<n;++i)
        {
            if(__builtin_popcount(i)!=cnt) continue;
            int no=0;
            for(int j=0;j<n;++j)
            {
                if(no>=p[j])
                {
                    ++no;
                    continue;
                }
                if(!((i>>j)&1))
                {
                    ++no;
                    continue;
                }
                if(j-no>=m)
                {
                    ++res;
                    break;
                }
                if(n-no<m)
                {
                    break;
                }
            }
        }
        res%=MOD;
    }while(next_permutation(p.begin(),p.end()));
    printf("%d\n",res);
}