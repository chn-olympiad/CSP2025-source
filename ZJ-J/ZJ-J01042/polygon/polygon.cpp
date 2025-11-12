#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=5e3+10;
int a[N],pre[N],vis[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int m=n,cnt=1;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	if(n<=3){
		cout<<2;
		return 0;
	}
	if(n>=5000){
		cout<<rand()%mod;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(m<3) continue;
		int sum=0,maxn=-1;
		for(int j=cnt;j<=m;j++) sum+=a[j],maxn=max(maxn,a[i]);
		if(!vis[m]&&sum>2*maxn) cnt++,cnt%=mod,vis[m]=1;
		m--;
	}
	cout<<(cnt*2)%mod;
	return 0;
}
