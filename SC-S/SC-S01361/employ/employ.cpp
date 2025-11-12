#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[20];
ll c[20];
ll peo[20];
ll n,m;
bool check(){
	ll pas=0;
	for(ll i=1;i<=n;i++){
		if((!s[i])||pas>=c[peo[i]]){
			pas++;
		}
	}
	if(pas>n-m) return 0;
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string st;
	cin>>st;
	for(ll i=1;i<=n;i++){
		s[i]=st[i-1]-'0';
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		peo[i]=i;
	}
	ll ans=0; 
	ans+=check();
	while(next_permutation(peo+1,peo+n+1)){
		ans+=check();
	}
	cout<<ans;
	return 0;
}