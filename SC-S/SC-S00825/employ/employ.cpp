#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=505,mod=998244353;
int n,m;
string s;
int co[N],ci[N];
lint ans;

bool vis[N];

line void dfs(int gvu,int day,int res){
	if(res>=m) ans=(ans+1)%mod;
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=true;
		bool f=co[day];
		bool g=gvu>ci[i]?1:0;
		bool ad=f+g;
		dfs(gvu+ad,day+1,res+ad^1);
		vis[i]=false;
	}
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;++i){
		co[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;++i) ci[i]=read();
	dfs(0,1,0);
	printf("%lld\n",ans/3);
	return 0;
}
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 
*/