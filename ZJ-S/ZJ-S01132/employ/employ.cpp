#include<bits/stdc++.h>
#define For(i,il,ir) for(int i=(il);i<=(ir);i++)
#define Rof(i,ir,il) for(int i=(ir);i>=(il);i--)
using namespace std;
const int mod=998244353;

int n,m;
int c[505];
char s[505];
int f[1<<20][20];
void qadd(int &x,int y){ x=(x+y>=mod)?(x+y-mod):(x+y); }
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    For(i,1,n){
        s[i]=getchar();
        while(s[i]!='0' && s[i]!='1') s[i]=getchar();
    }
    For(i,1,n) scanf("%d",&c[i]);
    f[0][0]=1;
    For(S,0,(1<<n)-1){
        int d=__builtin_popcount(S);
        For(i,1,n){
            if(!((S>>i-1)&1)){
                For(j,0,d){
                    int x=(s[d+1]=='0'||j>=c[i]);
                    qadd(f[S|(1<<i-1)][j+x],f[S][j]);
                }
            }
        }
    }
    int res=0;
    For(j,0,n-m) qadd(res,f[(1<<n)-1][j]);
    printf("%d\n",res);
    return 0;
}