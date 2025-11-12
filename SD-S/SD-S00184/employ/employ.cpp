#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e5+5;
int c[N];
const int MOD=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='1') cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(cnt==n){
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>i) cntt++;
		}
		int ans=1;
		for(int i=1;i<=cntt;i++) ans=ans%MOD*i%MOD;
		cout<<ans*m%MOD;
	}
	else if(m==1){
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0) cntt++;
		}
		cntt=cntt*cnt%MOD;
		cout<<cntt;
	}
	else {
		int ans=0;
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0) cntt++;
		}
		for(int i=1;i<=cnt;i++){
			ans+=i;
		}
		for(int i=1;i<=cntt;i++) ans=ans*i%MOD;
		cout<<ans%MOD;
	}
	return 0;
} 
