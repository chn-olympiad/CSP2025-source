#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],co;
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			co++;
		}
	}
	if(n-co>m){
		for(int i=1;i<=n;i++){
			ans=(ans*n)%998244353;
		}
	}else{
		for(int i=1;i<=co;i++){
			ans=ans*co%998244353;
		}
		for(int i=co+1;i<=n;i++){
			ans=(ans*n)%998244353;
		}
	}
	cout<<ans;
	return 0;
}

