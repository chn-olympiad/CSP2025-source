#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v[1005],p=0;
string s;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]==0)p+=1;
	}
	if(n-p<m){
		cout<<"0\n";
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i,ans%=998244353;
//		cout<<ans<<"\n";
	}
	cout<<ans%998244353<<"\n";
	return 0;
}/*
161088479
*/
