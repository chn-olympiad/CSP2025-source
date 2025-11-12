#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],s[500005],mx=0,mn=1,ans;
void solve1(){
	cout<<n/2;
}
void dfs(ll st,ll id){
	if(id>n){
		ans=max(ans,st);
		return;
	}
	for(int i=id;i<=n;i++){
		ll t=s[i]^s[id-1];
		if(t==k){
			dfs(st+1,i+1);
			return;
		}
	}
	dfs(st,id+1);
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
		mx=max(a[i],mx);
		mn=min(a[i],mn);
	}
	if(mx==mn)solve1();
	else if(k<=1){
		dfs(0,1);
		cout<<ans;
	}
	return 0;
}
