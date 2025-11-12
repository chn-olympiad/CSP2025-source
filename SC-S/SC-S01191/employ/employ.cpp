#include<bits/stdc++.h> 
using namespace std;
long long n,m,p,ans;
bool s[600],c[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1)p=1,ans++;
	}
	if(p==0){
		cout<<0%998244353;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cout<<ans%998244353;
	return 0;
}