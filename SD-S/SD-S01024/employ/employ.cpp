#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll qpow(ll a,ll b){
	ll ans=1,base=a;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;
		b>>=1; 
	}
	return ans;
}
int n,m;
string st;
int c[5050],d[5050];
ll f[(1<<18)+5][19],g[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>st;st='$'+st+'$';
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	bool A=1;
	for(int i=0;i<n;i++)A&=(st[i]=='1');
	//if(n<=18){
		f[0][0]=1;
		for(int s=0;s<(1<<n);s++){
			int r=__builtin_popcount(s);
			for(int k=0;k<=r;k++){
				for(int i=1;i<=n;i++){
					if(!(s&(1<<(i-1)))){
						if(r-k>=c[i]||st[r+1]=='0')
							(f[s|(1<<(i-1))][k]+=f[s][k])%=mod;
						else 
							(f[s|(1<<(i-1))][k+1]+=f[s][k])%=mod;
					}
				}
			}
		}
		ll ans=0;
		for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans<<endl;
		return 0;//25pts 
//	}
	if(m==1){
		ll ans=1,res=1,cnt=0;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		for(int i=1;i<=n;i++)d[c[i]]++;
		for(int i=0;i<=n;i++)d[i]+=d[i-1];
		for(int i=1;i<=n;i++){
			if(st[i]=='0'){
			//	cout<<i<<" "<<d[i-1]<<" "<<res<<endl;
				g[i]=d[i-1];
				res=res*d[i-1]%mod;
				for(int j=i-1;j<=n;j++)d[j]--;
			}else cnt++;
		}
		for(int i=1;i<=cnt;i++)res=res*i%mod;
		cout<<(ans-res+mod)%mod<<endl;
		return 0;
	}
	if(A){
		f[0][0]=1;
		for(int s=0;s<(1<<n);s++){
			int r=__builtin_popcount(s);
			for(int k=0;k<=r;k++){
				for(int i=1;i<=n;i++){
					if(!(s&(1<<(i-1)))){
						if(r-k>=c[i])
							(f[s|(1<<(i-1))][k]+=f[s][k])%=mod;
						else 
							(f[s|(1<<(i-1))][k+1]+=f[s][k])%=mod;
					}
				}
			}
		}
		ll ans=0;
		for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
	}
	return 0;
}

