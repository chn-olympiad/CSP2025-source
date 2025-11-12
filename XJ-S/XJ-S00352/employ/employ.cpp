#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,m,f[505],a[505],t[505],ans,b[505];
char s[505];
void solve(int q){
	if(q==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[i]){
				cnt++;
				continue;
			}
			if(t[i]==0){
				cnt++;
				continue;
			}
		}
		if(n-cnt>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			a[q]=b[i];
			solve(q+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//cout<<2432902008176640000%mod<<endl;
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')t[i]=0;
		if(s[i]=='1')t[i]=1;
	} 
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n<=18){
		solve(1);
		cout<<ans<<endl;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(t[i]==0||b[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*(n-i+1)%mod;
		}
		cout<<ans%mod<<endl;
	}
	
	return 0;
}
