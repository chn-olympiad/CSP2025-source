#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=998244353;
string s;
int a[510];
int c[510];
ll f[270000][20];
int gt(int x){
	int cnt=0;
	while(x){
		if(x&1){
			cnt++;
		}
		x/=2;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		cin>>c[i];
	}
	if(n<=18){
		f[0][0]=1;
		for(int i=1;i<=(1<<n)-1;i++){
			int cnt=gt(i);
			for(int j=0;j<m;j++){
				for(int k=1;k<=n;k++){
					if(((1<<(k-1))&i)==0)	continue;
					if(j>0){
						if(a[cnt] && (cnt-1)-(j-1)<c[k]){
							f[i][j]+=f[i^(1<<(k-1))][j-1];
						}
					}
					if(cnt-1-j>=c[k] || a[cnt]==0){
						f[i][j]+=f[i^(1<<(k-1))][j];
					}
					f[i][j]%=mod;
				}
			}
		}
		ll ans=1,sum=0;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		for(int i=0;i<m;i++){
//			cout<<i<<"  "<<f[(1<<n)-1][i]<<"\n";
			sum+=f[(1<<n)-1][i];
			sum%=mod;
		}
//		cout<<ans<<" "<<sum<<" ";
		cout<<(ans-sum+mod)%mod;
		return 0;
	}
	cout<<0;
	return 0;
}

