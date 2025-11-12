#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt0=0,cnt1=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='1')++cnt1;
		else ++cnt0;
	}
	if(cnt1<m)cout<<0;
	else if(cnt0==0){
		int res=1;
		for(int i=1;i<=n;++i){
			res=1ll*res*i%P;
		}
		cout<<res;
	}
	return 0;
}
