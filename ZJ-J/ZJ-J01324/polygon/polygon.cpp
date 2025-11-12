#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll> >j;
ll a[10010];
ll n;
vector<ll> b;
void dfs(ll num){
	if(num==n){
		j.push_back(b);
	}
	b.push_back(a[num]);
	dfs(num+1);
	b.pop_back(a[num]);
	dfs(num+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(flag){
		cout<<pow(2,n)-n-n*(n-1)/2-1;
	}else{
		dfs(0);
		ll nb=0;
		for(vector<ll> a:j){
			ll s=0,mx=INT_MIN;
			for(ll v:a){
				mx=max(mx,v);
				s+=v;
			}         
			if(s>mx*2){
				nb++;
				nb%=998244353;
			}
		}
		cout<<nb;
	}
	return 0;
}