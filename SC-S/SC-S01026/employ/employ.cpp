#include<bits/stdc++.h>
using namespace std;
int op[505];
int a[505];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f1=1;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		op[i]=c-'0';
		if(!op[i]) f1=0;
	}
	int cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt--;
	}
	if(cnt<m){
		cout<<0<<'\n';
		return 0;
	}
	if(f1){
		int l=n-cnt;
		
		long long ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		long long ans=1;
		for(int i=n;i>=1;i--){
			if(i==n) ans*=cnt;
			else ans*=i;
			ans%=mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}//20