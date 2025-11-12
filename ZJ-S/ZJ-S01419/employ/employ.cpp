#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5,mod=998244353;
ll n,m,ans,ss,c[N],w,an[N],fl;
char s[N];
bool vis[N];
bool ch(){
	fl=0;
	for(ll i=1;i<=w;i++){
		if(s[i]-'0'==1&&fl<c[an[i]]) fl--;
		fl++;
//		cout<<fl<<" ";
	}
//	cout<<fl<<endl;
	if(n-fl>=m) return 1;
	return 0;
}
void qpl(ll x){
	if(x==n+1){
		if(ch()) ans++;
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			an[++w]=i;
			qpl(x+1);
			vis[i]=0;
			w--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		ss+=s[i]-'0';
		if(s[i]-'0'==1) w=i;
	}
	for(ll i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	if(ss<m){
		cout<<0;
		return 0;
	}
	if(m==n||ss==n){
		ans=1;
		for(ll i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		ans=1;
		if(c[n]<=w-1){
			cout<<0;
			return 0;
		}
		for(ll i=1;i<n;i++){
			ans*=i;
			ans%=mod;
		}
		ll t=n,ts=0;
		while(c[t]>w-1) ts++;
		ans*=ts;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	w=0;
	qpl(1);
	cout<<ans;
	return 0;
}
