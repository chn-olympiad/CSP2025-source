#include<bits/stdc++.h>
#define For(i,il,ir) for(int i=(il);i<=(ir);i++)
#define Rof(i,ir,il) for(int i=(ir);i>=(il);i--)
using namespace std;
const int maxn=1e5+10;

int n,ans;
int a[maxn][4];
int b[maxn],c[maxn];
vector<int> ve[4];

void solve()
{
    scanf("%d",&n);
    For(j,1,3) ve[j].clear(); ans=0;

    For(i,1,n){
        int mx=-1,mx2=-1;
        For(j,1,3){
            scanf("%d",&a[i][j]);
            if(mx==-1 || a[i][j]>a[i][mx]) mx2=mx,mx=j;
            else if(mx2==-1 || a[i][j]>a[i][mx2]) mx2=j;
        }
        b[i]=mx,c[i]=mx2;
        ve[mx].push_back(a[i][mx]-a[i][mx2]);
        ans+=a[i][mx];
    }
    
    For(j,1,3){
        int sz=ve[j].size();
        if(sz>n/2){
            sz-=n/2;
            sort(ve[j].begin(),ve[j].end());
            For(i,0,sz-1) ans-=ve[j][i];
        }
    }
    printf("%d\n",ans);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--) solve();
    return 0;
}