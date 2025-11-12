#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353
int n,m,c[505],ys,flr,ktls,ans;
string s;
int jc(int x){
	int ret=1;
	for(int i=1;i<=x;i++){
		ret*=i;
		ret%=mod;
	}
	return ret;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			flr++;
		}
	}
	int t=0;
	for(int i=0;i<n;i++){
		ys+=s[i]-'0';
		if(s[i]=='1'){
			t=1;
		}
		if(t!=1){
			ktls++;
		}
	}
	if(m==n){
		if(ys!=n){
			cout<<"0";
		}else if(flr!=n){
			cout<<"0";
		}else{
			cout<<jc(n);
		}
		return 0;
	}else if(m==1){
		if(flr<=ktls){
			cout<<"0";
			return 0;
		}
		ans=jc(flr)/jc(ktls)/jc(ktls);
		ans*=(flr-ktls);
		n=n-ktls-1;
		ans*=jc(n);
		cout<<ans;
		return 0;
	}
	return 0;
}
