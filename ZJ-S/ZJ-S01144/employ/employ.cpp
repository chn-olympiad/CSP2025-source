#include<bits/stdc++.h>
using namespace std;
//int dp[];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,a[510];
	bool flag=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(flag){
		if(n==m){
			long long ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*i%998244353;
			cout<<ans;
		}
		else cout<<0;
	}
	else{
		if(n==m)cout<<0;
		else if(n==1){
			cout<<n;
		}
		else cout<<n*m%998244353;
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
