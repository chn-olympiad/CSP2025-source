#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;
int n,m,c[N];
string s;
bool check(){
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') return 0;
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(check()){
		long long jc=1;
		for(int i=2;i<=n;i++){
			jc*=i;
			jc%=mod;
		}
		cout<<jc<<'\n';
	}
	return 0;
}
