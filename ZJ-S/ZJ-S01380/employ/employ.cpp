#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;
int n,m;
string s;
int c[N],p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s='%'+s;
	int f=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1')f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	if(n<=18){
		int ans=0;
		do{
			int cnt=0,tot=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					cnt++;
				}else if(s[i]=='1'){
					if(cnt<c[p[i]]){
						tot++;
				}else{
						cnt++;
					}
				}
				if(tot>=m)break;
			}
			if(tot>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
		return 0;
	}
	if(f){
		ll ans=1;
		int k=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0)k--;
		}
		if(k<m){
			cout<<0<<'\n';
			return 0;
		}
		for(int i=1;i<=k;i++){
			ans=ans*i%mod;
			//cout<<ans<<'\n';
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0<<'\n';
				return 0;
			}
		}
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	cout<<0<<'\n';
	return 0;
}