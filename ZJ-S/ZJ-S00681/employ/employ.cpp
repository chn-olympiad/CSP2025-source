#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=1145;
int n,m,ans,c[N],f[N];
char s[N];
bool check(){
	for(int i=1;i<=n;i++)
		if(s[i]=='0')return 0;
	return 1;
}
void sc(int x,int spi){
	if(n-spi<m)return ;
	if(x==n+1){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			if(s[x]=='0'||spi>=c[i])sc(x+1,spi+1);
			else sc(x+1,spi);
			f[i]=0;
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i];

	if(m==1){
		int sum=1;
		for(int i=1;i<=n;i++)sum=sum*i%mod;
		sort(c+1,c+1+n);
		int ans=1,cnt=0,l=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')cnt++;
			else{
				while(l<n&&c[l+1]<=i-1)++l;
				ans=ans*(l-(i-1-cnt))%mod;
			}
		}
		for(int i=cnt;i>=1;i--)ans=ans*i%mod;
		cout<<(sum-ans+mod)%mod;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||c[i]==0){
				cout<<0;return 0;
			}
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	sc(1,0);
	cout<<ans;
	return 0;
}