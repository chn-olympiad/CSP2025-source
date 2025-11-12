#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,m,num=0;cin>>n>>m;
	string s;cin>>s;
	vector<ll> C(n);
	for(ll i=0;i<n;i++)cin>>C[i];
	sort(begin(s),end(s));
	do{
		ll ans=0,cnt=0;
		for(ll i=0;i<n;i++){
			if(cnt>=C[i]){cnt++;continue;}
			if(s[i]=='1')ans++;
			if(s[i]=='0')cnt++;
		}
		if(ans>=m)(num+=1)%=mod;
	}while(next_permutation(begin(s),end(s)));
	cout<<num;
	return 0;
}