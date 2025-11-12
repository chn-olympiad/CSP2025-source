#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
const int mod=998244353;
int n,m;
int c[25],f[1<<18][20];
bool b[25];
inline void get(int &x){if(x>=mod)x-=mod;}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int i,j,k,ans=0;cin>>n>>m;
    for(i=1;i<=n;i++){
        char ch;cin>>ch;
        b[i]=ch-'0';b[i]^=1;
    }for(i=1;i<=n;i++)cin>>c[i];
    f[0][0]=1;
    for(i=0;i<(1<<n);i++){
		int a=__builtin_popcount(i);
        for(j=0;j<=a;j++)
            for(k=0;k<n;k++)
                if(!(i>>k&1))get(f[i^(1<<k)][j+(b[a+1]|(c[k+1]<=j))]+=f[i][j]);
	}
    for(i=n-m;~i;i--)get(ans+=f[(1<<n)-1][i]);
    cout<<ans;
}
