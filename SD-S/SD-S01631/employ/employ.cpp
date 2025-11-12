#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inline
const ll N=2e5+10;
const ll mod=998244353;
ll n,m;
ll s[N];
ll c[N];
ll num[20];
ll ans=0;
bool check(){
//	for(int i=1;i<=n;i++){
//		cout<<num[i]<<" ";
//	}
	ll cnt=0;
	ll res=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			cnt++;
		}
		else{
			if(cnt>=c[num[i]]){
				cnt++;
			}
			else{
				res++;
			}
		}
	}
//	cout<<res<<"\n";
	return res>=m;
}
void dfs(ll x,ll st){
	num[st]=x;
	if(st==n){
		if(check()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		bool fl=1;
		for(int j=1;j<=st;j++){
			if(num[j]==i) fl=0;
		}
//		cout<<i<<" "<<st<<"\n";
		if(!fl) continue;
		dfs(i,st+1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string t;
	cin>>t;
	bool fl=1;
	for(int i=1;i<=n;i++){
		s[i]=t[i-1]-'0';
		if(s[i]!=1){
			fl=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(fl){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod; 
		}
		cout<<ans<<"\n";
		return 0;
	}
	dfs(1,0);
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}


