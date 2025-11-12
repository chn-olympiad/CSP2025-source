#include<iostream>
#include<algorithm>
#include<vector>
#define pb push_back
#define lb lower_bound
#define ppc __builtin_popcount 
using namespace std;
const int N=510;
const int M=(1<<18)+10;
const int TT=5e5+10;
const int K=20;
const int mod=998244353;
void add(int &a,int b) {a+=b;if(a>=mod)a-=mod;}
int qpo(int a,int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod,b>>=1; 
	}
	return r;
}
int n,m,res,a[N],id[M],c[N],f[2][TT][K][K];
vector <int> d[N];
string s;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=" "+s;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int S=0;S<(1<<n);S++)
	{
		int tc=ppc(S);
		id[S]=d[tc].size(),d[tc].pb(S);
	}
	f[0][0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int cur=(i&1),last=1-cur;
		for(int S=0;S<(int)d[i].size();S++) for(int j=0;j<=i;j++) for(int k=0;k<=i;k++)
			f[cur][S][j][k]=0;
		for(int S=0;S<(int)d[i-1].size();S++) for(int j=0;j<=i;j++) for(int k=0;k<=i;k++)
			if(f[last][S][j][k]) for(int t=0;t<n;t++) if(!((d[i-1][S]>>t)&1))
			{
				bool fn=(s[i]=='1'&&j<a[t]); int nS=id[d[i-1][S]|(1<<t)];
				if(fn) add(f[cur][nS][0][k+1],f[last][S][j][k]);
				else add(f[cur][nS][j+1][k],f[last][S][j][k]);
			}
	}
	for(int j=0;j<=n;j++) for(int k=m;k<=n;k++) add(res,f[n&1][0][j][k]);
	cout<<res;
	return 0;
}
