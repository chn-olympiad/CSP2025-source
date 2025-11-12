#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[1000];
string s;
int main(){
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans1=1;
	for(int i=1;i<=n;i++){
		ans1=ans1*i;
		ans1=ans1%998244353;
	}
	cout<<ans1;
	return 0;
}
