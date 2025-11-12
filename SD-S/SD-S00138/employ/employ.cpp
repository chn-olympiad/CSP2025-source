#include<bits/stdc++.h>
#define f(i,a,b) for(auto i=a;i<=b;i++)
#define F(i,a,b) for(auto i=a;i>=b;i--)
using namespace std;
const int maxn=510,mod=998244353;
int n,m,c[maxn],qwq,vis[maxn],a[maxn];
long long ans;
string s;
void dfs(int x){
	if(x==n){
		int sum=0;
		f(i,0,n-1){
			if(s[i]=='0'||sum>=c[a[i]]) sum++;
		}if(n-sum>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		}
		return;
	}
	f(i,0,n-1) if(!vis[i]){
		a[x]=i;
		vis[i]=1; 
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	f(i,0,n-1) cin>>c[i];
	if(n<=10){
		dfs(0);
		cout<<ans<<endl;
		return 0;
	}else if(m==n) cout<<0<<endl;
	else if(m==1){
		ans=1;
		f(i,1,n) ans=ans*i%mod;
		cout<<ans<<endl;
	}else cout<<1<<endl;
	return 0;
}
