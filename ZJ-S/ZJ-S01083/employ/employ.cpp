#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,c[1000],u[1000];
string s;
ll A(ll p){
	ll q=1;
	for(int i=2;i<=p;i++){
		q*=i;
		q%=998244353;
	}
	return q;
}
void dfs(int p,int b,int g){
	if(p==n+1){
		if(g>=m)ans++;
		ans%=998244353;
		return ;
	}
	if(g>=m){
		ans+=A(n-p+1);
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			u[i]=1;
			if(s[p-1]=='0'||b>=c[i]){
				dfs(p+1,b+1,g);
			}
			else{
				dfs(p+1,b,g+1);
			}
			u[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
