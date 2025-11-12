#include<bits/stdc++.h>
using namespace std;
long long n,m,mod=998244353,cnt=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		int aa;
		cin>>aa;
		aa=!aa;
		m+=aa;
		cnt=cnt*i%mod;
	}
	if(m>n){
		cout<<0;
		return 0;
	}
	cout<<cnt;
	return 0;
} 
