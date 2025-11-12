#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+5;
const int mod=998244353;
int n,m,c[505];
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		cout<<1;
		return 0;
	}
	int f=0;
	for(int i=0;i<s.size();i++)if(s[i]!='1')f=1;
	if(f==0){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	return 0;
}