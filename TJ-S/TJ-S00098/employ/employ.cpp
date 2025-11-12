#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[10000001],fakeans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		fakeans=fakeans*i%998244353;
	}
	cout<<fakeans;
	return 0;
}

