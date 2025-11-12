#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510;
const ll p=998244353;
ll n,m,k,a[N],x;
string s;
void solve(){
	cin>>n>>m;
	cin>>s;
	x=n;k=1;
	while(x>=1){
		k=k*x%p;
		x--;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<k%p;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}