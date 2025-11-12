#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5010,MOD=998244353;
int n,a[MAXN],f[MAXN],maxx,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	f[0]=1;
	f[a[1]]++;
	f[a[2]]++;
	f[min(a[1]+a[2],maxx+1)]++;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=maxx+1;j++) ans=(ans+f[j])%MOD;
		f[maxx+1]=(f[maxx+1]*2)%MOD;
		for(int j=maxx;j>=0;j--){
			int k=min(a[i]+j,maxx+1);
			f[k]=(f[k]+f[j])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
