#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=550;
int bj[N],vis[N];
int ans;
const int mod=998244353;
char s[N];
int c[N];
int n,m;
void pan(){
	int cnt=0;
	FOR(i,1,n){
		if(s[i]=='0'){
			++cnt;
		}
		else {
			if(cnt>=c[bj[i]]) ++cnt;
		}
	}
	if(n-cnt>=m) ++ans;
	if(ans>=mod) ans-=mod;
}
void dfs(int x){
	if(x>n){
		pan();
		return ;
	}
	FOR(i,1,n){
		if(vis[i]) continue;
		bj[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=iread();
	m=iread();
	scanf("%s",s+1);
	FOR(i,1,n) c[i]=iread();
	int bj=0;
	FOR(i,1,n){
		if(s[i]=='0') bj=1;
		break;
	}
	if(!bj&&n>11){
		int cnt=n;
		FOR(i,1,n){
			if(!c[i]) --cnt;
		}
		if(cnt<m){
			puts("0");
			return 0;
		}
		ll res=1;
		FOR(i,1,n){
			res=res*i%mod;
		}
		printf("%lld",res);
		return 0;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}


