#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(b);i>=(a);i--)
using namespace std;
/*
*/
typedef long long ll;
const int N=1e5+5;
ll m,n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ll ans=1;ll ans2=0;
	for(ll i=n;i>=1;i--){
		ans=ans*i;
		ans=ans%998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
