#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 505
using namespace std;
ll n,m;
ll ans=0;
bool s[N];
ll a[N];
bool vis[N];
void dfs(int step,int sum){
	if(step>n){
		if(n-sum>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		int d=(sum>=a[i])||(s[step]==0);
		dfs(step+1,sum+d);
		vis[i]=0;
	}
	return ;
}
void subsolve(){
	dfs(1,0);
	cout<<ans;
	return ;
}
ll jiecheng(){
	ll ret=1;
	for(int i=1;i<n;i++){
		ret=(ret*i)%mod;
	}
	return ret;
}
ll getnum(){
	ll ret=1,cnt=0,w=0;
	priority_queue<ll,vector<ll>,greater<ll> >q;
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	
	for(int i=1;i<=n;i++){
		if(!s[i])continue;
		w++;
		while(q.top()<=i-1){
			cnt++;
			q.pop();
		}
		ret=(ret*cnt)%mod;
		cnt--;
		if(cnt<0)return 0;
	}
	for(int i=1;i<=n-w;i++){
		ret=(ret*i)%mod;
	}
	return ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=(x=='1');
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		cout<<0;
		return 0;
	}
	if(n<=10){
		subsolve();
		return 0;
	}
	cout<<((ll)jiecheng()*n-(ll)getnum())%mod;
	return 0;
}
/*
10 1
0010001101
0 0 1 3 3 5 6 10 10 10

3369600
*/