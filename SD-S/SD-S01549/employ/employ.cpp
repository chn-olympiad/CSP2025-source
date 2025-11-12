#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=501;
const ll mod=998244353;
ll n,m,ans;
char s[N];
ll c[N];
bool vis[N];
ll a[N],t[N];
void dfs(ll x){
	if(x==n+1){
		memset(t,0,sizeof(t));
		for(ll i=1;i<=n;i++){
			if(s[i]=='0') t[i]++;
			else if(t[i]>=c[a[i]]){
				t[i]++;
			}
			t[i+1]=t[i];
//			cout<<a[i]<<" "<<t[i]<<" "<<c[a[i]]<<"    ";
		}
//		cout<<t[n]; 
		if(n-t[n]>=m){
			ans=(ans+1)%mod;
		}
//		cout<<endl;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void solve1(){
	dfs(1);
	cout<<ans;
}
bool flag;
void solve2(){
	ans=1;
	for(ll i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')
			flag=1;
	}
	for(ll i=1;i<=n;i++)
		cin>>c[i];
	if(n<=10) solve1();
	else if(flag==0) solve2();
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
