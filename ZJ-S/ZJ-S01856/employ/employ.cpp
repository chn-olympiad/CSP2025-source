#include<bits/stdc++.h>
using namespace std;
long long n,s,f[505],m,k,mod=998244353,ans;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		f[i]=f[i-1];
		if(c=='0')f[i]++;
		else{
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	if(m==n){
		if(k!=n){
			cout<<"0";
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	if(k==n){
		ans=1;
		for(int i=n;i>=n-m+1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(k<m){
		cout<<"0";
		return 0;
	}
	return 0;
}
