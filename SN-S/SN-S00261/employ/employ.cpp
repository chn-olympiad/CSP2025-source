#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int f(int x){
	int s=1;
	for(int i=1;i<=x;i++){
		s=((s%mod)%mod*(i%mod)%mod)%mod;
	}
	return s;
}
int n,m,a[510];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cout<<0<<endl;
			return 0;
		}
	}
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<f(n);
	return 0;
}
