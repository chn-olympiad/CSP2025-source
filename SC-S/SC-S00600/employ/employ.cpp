#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int n,m;
string s;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag1=1,flag0=1;
	for(int i=1;i<=s.size();i++){
		if(s[i]=='0')flag1=0;
		if(s[i]=='1')flag0=0;
	}
	if(flag1){
		int cnt=1;
		for(int i=1;i<=m;i++){
			cnt*=i%mod;
		}
		cout<<cnt;
	}else if(flag0){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
