#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=2*n;i++) cin>>x;
	ll pro=1;
	for(int i=n;i>=1;i--) pro=pro*i%998244353;
	cout<<pro;
	return 0;
}
