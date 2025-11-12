#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],sum,ans=1;
string s;
int main(){
	freopen("employ3.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	s=" "+s;
	for(int i=1;i<=n;i++){
		sum+=(s[i]=='1');
	}
	if(sum<m){
		cout<<"0";
		return 0;
	}
	if(sum==n){
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

