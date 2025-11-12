#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=511,mo=998244353;
int n,m,lim,cnt[N<<1],sum[N<<1],C[N][N];
int a[N],f[N][N],g[N][N],jc[N];

inline void upd(int &x,long long y){x=(x+y)%mo;}

signed main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);

	cin>>n>>lim;
	a[1]=1;
	for (int i=1;i<=n;++i){
		char ch;
		cin>>ch;
		if (ch=='1') ++m,a[m+1]=a[m];
		else ++a[m+1];
	}

	for (int i=m+1;i<=n+1;++i) a[i]=n+2;
	for (int i=1;i<=n;++i){
		int x; cin>>x; ++cnt[x];
	}
	sum[0]=cnt[0];
	for (int i=1;i<(N<<1);++i) sum[i]=sum[i-1]+cnt[i];

	for (int i=0;i<N;++i){
		C[i][0]=1;
		for (int j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	jc[0]=1;
	for (int i=1;i<N;++i) jc[i]=(long long)jc[i-1]*i%mo;

	// for (int i=1;i<=n;++i) cout<<a[i]<<(i==n?'\n':' ');
	// for (int i=1;i<=n+1;++i) cout<<cnt[i]<<(i==n+1?'\n':' ');

	f[0][sum[a[1]-1]]=1;
	for (int i=1;i<=n;++i){
		memset(g,0,sizeof(g));
		for (int j=0;j<=i;++j) for (int k=0;k<=n;++k) if (f[j][k]){
			int t=sum[a[i]+j-1]-k;
			if (k){
				int now=sum[a[i+1]+j]-sum[a[i]+j-1];
				for (int p=0;p<=now;++p) if (p<=i-1-t)
					upd(g[j+1][k-1+(now-p)],(long long)f[j][k]*k%mo*C[now][p]%mo*C[i-1-t][p]%mo*jc[p]);
			}
			int now=sum[a[i+1]+j-1]-sum[a[i]+j-1];
			for (int p=0;p<=now;++p) if (p<=i-t)
				upd(g[j][k+(now-p)],(long long)f[j][k]*C[now][p]%mo*C[i-t][p]%mo*jc[p]);
				// cout<<i<<' '<<j<<' '<<k<<' '<<p<<' '<<now<<' '<<(long long)f[i][j][k]*C[now][p]%mo*C[i-t][p]%mo*jc[p]%mo<<'\n';
		}
		memcpy(f,g,sizeof(f));
	}

	// for (int i=0;i<=n+1;++i) for (int j=0;j<=n;++j) for (int k=0;k<=n;++k) if (f[i][j][k])
	// 	cout<<"f["<<i<<"]["<<j<<"]["<<k<<"]"<<'('<<sum[a[i]+j-1]-k<<')'<<"="<<f[i][j][k]<<'\n';

	long long ans=0;
	for (int i=0;i<=n-lim;++i) upd(ans,f[i][0]);
	cout<<(ans%mo+mo)%mo<<'\n';

	return 0;
}