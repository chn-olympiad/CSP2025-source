#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],mod=998244353;
string s;
long long ds(long long a){
	long long ans=1;
	for(int i=1;i<=a;i++){
		ans=(ans*i)%mod;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			flag=0;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=0;
		}
	}
	if(m==n){
		if(flag==1){
			cout<<ds(n);
		}else{
			cout<<0;
		}
	}
	return 0;
}
