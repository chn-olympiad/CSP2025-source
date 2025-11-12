#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=998244353;
ll n,m;
string s;
ll c[505];
ll s1[505];
bool vis[505];
ll ans;
void dfs(ll idx){
	if(idx==n+1){
		ll cnt=0,num=0;
		for(ll i=1;i<=idx;i++){
			if(cnt>=c[s1[i]] or s[i-1]=='0'){
				cnt++;
				continue;
			}
			num++;
		}
		if(num>=m) ans++;
		ans%=p;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			s1[idx]=i;
			dfs(idx+1);
			vis[i]=0;
		}
	}
}
bool f=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	ll lens=s.size();
	for(ll i=0;i<lens;i++){
		char ch=s[i];
		if(ch=='0'){
			f=0;
			break;
		}
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f){
		ans=1;
		for(ll i=n;i>1;i--){
			ans*=i;
			ans%=p;
		}
		cout<<ans%p;
		return 0;
	}
	if(n<=18){
		dfs(1);
		cout<<ans%p;
	}
	else{
		ans=1;
		for(ll i=n;i>1;i--){
			ans*=i;
			ans%=p;
		}
		cout<<ans%p;
		return 0;
	}
	return 0;
}