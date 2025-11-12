#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=998244353;
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string s1;
	cin>>s1;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
	}
	ll ans=1;
	for(int i=1;i<=m;i++){
		ans*=i;
		ans%=N;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
