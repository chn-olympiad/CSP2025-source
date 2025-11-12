#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=505,mod=998244353;

int n,m;
char s[maxn];
int c[maxn];
ll ansf;

void dfs(int dep,int cast,int cnt,int t){
	if(cnt>=m){
		ll x=1;
		for(int i=1;dep+i<=n+1;i++){
			x*=i; x%=mod;
		}
		ansf+=x; ansf%=mod;
		return;
	}
	if(dep>n){
		if(cnt>=m){
			ansf++;
			ansf%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if((t&(1<<(i-1)))) continue;
		else if(cast>=c[i]) dfs(dep+1,cast+1,cnt,t|(1<<(i-1)));
		else if(s[dep]=='0') dfs(dep+1,cast+1,cnt,t|(1<<(i-1)));
		else{
			dfs(dep+1,cast,cnt+1,t|(1<<(i-1)));
		}
	}
}

void solve1(){
	dfs(1,0,0,0);
	cout<<ansf<<endl;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	solve1();
}
