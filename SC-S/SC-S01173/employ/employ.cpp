#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),t(n);
	string s;
	cin>>s;
	bool ta=true,tb=true;
	for(int i=0;i<n;i++){
		t[i]=(s[i]=='1'?1:0);
		ta&=(s[i]=='1');
		tb&=(s[i]=='0');
	}
	if(n==m&&!ta){
		cout<<0;
		return 0;
	}if(tb){
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(int i=0;i<n;i++){
		ans*=(n-i);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}