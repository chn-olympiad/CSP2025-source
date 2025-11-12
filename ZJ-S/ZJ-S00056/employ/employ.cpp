#include <bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define ll long long 
const int N=500+10;
const int mod=998244353;
ll n,m,c[N],ans,vis[N],se[N];
string s;
void dfs(ll x,ll cnt,ll temp){
	if(x>n&&cnt>=m){
		ans=(ans+1)%mod;
		return;
	}
	if(x>n&&cnt<m) {
		return;	
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			//se[i]=x;
			if(temp<c[i]&&s[x]=='1') dfs(x+1,cnt+1,temp);
			else dfs(x+1,cnt,temp+1);
			vis[i]=0; 
		}
	}
}
int main()
{
  	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	s='#'+s;
	ll cnt=0;
	for(int i=1;i<=s.size();i++)
		if(s[i]=='1') cnt++;
	if(cnt==n){
		ll temp=1;
		for(int i=1;i<=m-1;i++)
			temp*=i;
		for(int i=m;i<=n;i++){
			ll t=1;
			temp*=i;
			for(int j=n-m+1;j<=n;j++)
				t*=j;
			ans=(ans+t/temp)%mod;
		}
	}
	else dfs(1,0,0);
	cout<<ans;
 	return 0;
}

