#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m!=n){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cout<<0;
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	
	return 0;
}
