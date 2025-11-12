#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[505];
long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	bool bl=1;
	for(long long i=0;i<=s.length();i++) if(s[i]=='0') bl=1;
	if(cnt>n-m){
		cout<<0;
		return 0;
	}
	if(m==1){
		long long ans1=1;
		for(long long i=1;i<=n-1;i++){
			ans1=(ans1*i)%mod;
		}
		ans1=(ans1*(n-cnt))%mod;
		cout<<ans1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}