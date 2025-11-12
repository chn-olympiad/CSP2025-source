#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e3+5,mod=998244353;
int n,m;
string s;
int c[N]; 

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 
