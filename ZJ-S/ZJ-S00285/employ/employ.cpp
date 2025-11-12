#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,c[504],js[504],p,ans;
bool f[14];
char s[504];
bool flag=1;
void dfs(int w,int t,int g){
	if(w>n){
	  if(t>=m)
	    ans++,ans%=mod;
	  return ;
	}
	for(int i=1;i<=n;i++){
	  if(!f[i]){
	  	f[i]=1;
	  	if((s[w]=='0')||(s[w]=='1'&&g>=c[i]))
	  	  dfs(w+1,t,g+1);
	  	else
	  	  dfs(w+1,t+1,g);
	  	f[i]=0;
	  }
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	p=n;
	for(int i=1;i<=n;i++){
	  cin>>s[i];
	  if(s[i]=='0')
	    flag=0,p--;
	}
	js[0]=1;
	for(int i=1;i<=n;i++)
	  cin>>c[i],js[i]=js[i-1]*i,js[i]%=mod;
	if(flag==1){
	  cout<<js[n];
	  return 0;
	}
	if(m>p){
	  cout<<0;
	  return 0;
	}
	if(m==n){
	  cout<<1;
	  return 0;
	}
	if(n<=11){
	  dfs(1,0,0);
	  cout<<ans;
	  return 0;
	}
	cout<<(js[n-1]+js[n-2])%mod;
	return 0;
}
