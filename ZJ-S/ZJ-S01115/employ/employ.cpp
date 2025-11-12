#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10;
const int mod=998244353;
int n,m;
int a[N];
char s[N];
int pw[N];
int cnt=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	pw[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*i;
		pw[i]=(pw[i]%mod+mod)%mod;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==0)cnt++;
	}
	int ans=((pw[n])/(pw[m]*pw[n-m]%mod*pw[cnt]%mod)+mod)%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<'\n';
	return 0;
}
