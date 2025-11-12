#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int mod=998244353;
char hh[505];
int c[505],a[505],ans,h[505],s[505],rty,rty1;
bool ff;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>hh[i];
		if(hh[i]=='0'){
			h[i]=1;
			ff=1;
		}
		else{
			rty++;
		}
		s[i]=s[i-1]+h[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)rty1++;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	if(rty<m||(n-rty1)<m){
		cout<<"0";
		return 0;
	}
	if(ff==0&&rty1==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	while(1){
		int ok=0,op=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]>op&&hh[i]=='1')ok++;
			else op++;
		}
		if(ok>=m){
			ans++;
		}
		if(next_permutation(a+1,a+1+n)==0)break;
		
	}
	cout<<ans%mod;
	return 0;
}