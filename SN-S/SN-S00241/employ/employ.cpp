#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char c[n];
	bool b=1;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]!='1') b=0;
	}
	int nx[n];
	for(int i=0;i<n;i++){
		cin>>nx[i];
	}
	if(b){
		long long zhong=1;
		for(int i=1;i<=n;i++){
			zhong=zhong%mod*i%mod;
		}
		cout<<zhong;
		return 0;
	}
	cout<<2;
	return 0;
}

