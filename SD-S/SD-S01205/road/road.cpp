#include<bits/stdc++.h>
using namespace std;

#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif

typedef long long ll;
typedef pair<ll,ll>pll;

inline ll max(const ll&a,const ll&b,const ll&c){
	return max(a,max(b,c));
}

inline ll min(const ll&a,const ll&b,const ll&c){
	return min(a,min(b,c));
}

template<typename T>
inline void read(T&a){
	a=0;
	bool f=0;
	char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=1;
		}c=gc();
	}while(c>='0'&&c<='9'){
		a=(a<<3)+(a<<1)+(c&15);
		c=gc();
	}a=f?~a+1:a;
	return;
}

template<typename T,typename...Tp>
inline void read(T&a,Tp&...b){
	read(a);
	read(b...);
	return;
}

template<typename T>
inline void write(T a){
	if(a<0){
		pc('-');
		a=~a+1;
	}if(a>=10){
		write(a/10);
	}pc(a%10+'0');
	return;
}

inline void write(char a){
	pc(a);
	return;
}

template<typename T,typename...Tp>
inline void write(T a,Tp...b){
	write(a);
	write(b...);
	return;
}

ll t,n,a[111111][5],cnt[5],m,k;
ll ans=0;

void dfs(ll u,ll ret){
	if(u==n){
		ans=max(ans,ret);
		return;
	}
	for(ll i=1;i<=3;i++){
		if(cnt[i]>=n/2){
			continue;
		}
		cnt[i]++;
		dfs(u+1,ret+a[u+1][i]);
		cnt[i]--;
	}return;
}

ll to[2222222],nxt[2222222],head[2222222],w[2222222];
ll tot;

inline void add(ll u,ll v,ll c){
	to[tot]=v;
	w[tot]=c;
	nxt[tot]=head[u];
	head[u]=tot++;
	return;
}

ll cost;
ll vis[1111111];

void dfs(ll u,ll cnt,ll cos){
	if(cnt==n){
		cost=min(cost,cos);
		return;
	}for(ll i=head[u];~i;i=nxt[i]){
		ll v=to[i];
		ll c=w[i];
		if(vis[i]){
			continue;
		}vis[v]=1;
		dfs(v,cnt+1,cos+c);
		vis[v]=0;
	}return;
}

void run(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	read(n,m,k);
	memset(head,-1,sizeof(head));
	for(ll i=1;i<=m;i++){
		ll u,v,c;
		read(u,v,c);
		add(u,v,c);
		add(v,u,c);
	}cost=INT_MAX;
	for(ll i=1;i<=k;i++){
		ll c,cs;
		read(c);
		for(ll j=1;j<=n;j++){
			read(cs);
		}
	}
	return;
}

int main(){
	run();
	return 0;
} 
