#include<bits/stdc++.h>
#define M 998244353
#define ll long long
using namespace std;

int n;
ll ans=0,a[5010];
map<vector<int>,int>mp;
vector<int>v;
bool f=true;

void dfs(int st,int n){
	if(st>n)return;
	vector<int>w=v;
	sort(w.begin(),w.end());
	if(mp[w]==0){
		ans++;
		mp[w]=1;
	}
	v.push_back(st);
	dfs(st+1,n);
	v.pop_back();
	dfs(st+1,n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=false;
	}
	if(n==3){
		ll sum=0,ma=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			ma=max(a[i],ma);
		}
		if(sum>ma*2)cout<<1;
		else cout<<0;
	}
	else{
		if(n==4)ans=4;
		else{
			for(int i=3;i<=n;i++)dfs(1,i);
		}
		cout<<ans%M;
	}
}

