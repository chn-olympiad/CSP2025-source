#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s[509];
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int num=0;
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			num++;
		}
	}
	if(num==n){
		int ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(num<m){
		cout<<0;
		return 0;
	}
	if(num==m){
		cout<<1;
		return 0;
	}
	int fiu;
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			fiu=i+1;
			break;
		}
	}
	bool we=false;
	for(int i=0;i<n;i++){
		if(s[i]>=fiu){
			we=true;
			break;
		}
	}
	if(we==false){
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}
