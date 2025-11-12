#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[555];
char s[555];
int ans,f=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s[i];
		if(s[i]=='0'){
			f=0;
		}
	}
	for(int i=1; i<=n; i++){
		cin>>c[i];
		if(c[i]=='0'){
			f=0;
		}
	}
	if(f==1){
		ans=1;
		for(int i=n; i>=1; i--){
			ans*=i;
			ans%=mod;
		}
	}
	else{
		ans=0;
	}
	cout<<ans;
	return 0;
}