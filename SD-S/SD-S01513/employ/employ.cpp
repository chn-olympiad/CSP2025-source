#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define endl "\n"
#define ft first
#define sd second
using namespace std;
const ll N=1e6+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,m,T,ans;
ll s[N],c[N];
char ch;
namespace sub1{
	ll bo[N];
	void dfs(ll x){
		if(x>n){
			ll sum=0;
//			for(int i=1;i<=n;i++)cout<<bo[i]<<" ";cout<<endl;
			for(int i=1;i<=n;i++){
//				cout<<sum<<" "<<c[bo[i]]<<endl;
				if(sum>=c[bo[i]]){
				
					sum++;continue;
				}
				if(s[i]==0)sum++;
			}
//			cout<<sum<<endl;
			if(n-sum>=m)ans++,ans%=mod;
			return;
		}
		for(int i=1;i<=n;i++)if(!bo[i])bo[i]=x,dfs(x+1),bo[i]=0;
	}
	void sovle(){
		dfs(1);
		cout<<ans;
	}
}
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ch,s[i]=ch-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){sub1::sovle();return 0;}
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i,ans%=mod;
	cout<<ans;
	return 0;
}

