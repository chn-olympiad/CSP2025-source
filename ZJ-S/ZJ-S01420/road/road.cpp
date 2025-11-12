#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+4;
const int M = 1e6+5;
ll read(){
	ll x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=1ll*x*10+s-'0';
		s=getchar();
	}return 1ll*x*f;
}
int n,m,k;
int cnt;
//int head[N],nxt[(M<<1)+N*10],to[(M<<1)+N*10],cnt;
//ll w[(M<<1)+N*10];
//void add(int u,int v,int e){
//	nxt[++cnt] = head[u];
//	head[u] = cnt;
//	w[cnt] = e;
//	to[cnt] = v;
//}

priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;

int f[N];
int findd(int x){
	if (f[x] == x) return x;
	else return f[x] = findd(f[x]);
}
int to[(M<<1)+N*20],fr[(M<<1)+N*20];

void merge(int x,int y){
	x=findd(x),y=findd(y);
	f[y] = x;
}
bool check(){
	for(int i=1;i<n;i++) {
		if (findd(i)!=findd(i+1)) return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),e=read();
		//add(u,v,e);
		to[++cnt] = v;fr[cnt] = u;
		q.push(make_pair(e,cnt));
		//add(v,u,e);
		to[++cnt] = u;fr[cnt] = v;
		q.push(make_pair(e,cnt));
	}
	for(int i=1;i<=k;i++){
		ll c = read();
		for(int j=1;j<=n;j++){
			ll x= read();
//			add(n+i,j,x+c);
//			add(j,n+i,x+c);
//			to[++cnt] = n+i;fr[cnt] = j;
//			q.push(make_pair(x+c,cnt));
			to[++cnt] = j;fr[cnt] = n+i;
			q.push(make_pair(x+c,cnt));
		}
	}
	ll ans = 0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=n+k;i++) 
	{
		pair<ll,int> t = q.top();
		q.pop();
		while(!q.empty()&&findd(to[t.second]) == findd(fr[t.second])){
			t = q.top();
			q.pop();
		//	printf("%d %d fa%d\n",to[t.second],fr[t.second]);
			
		}
	
		merge(to[t.second],fr[t.second]);
		ans += t.first;
		if (i>=n-1) {
			if (check()) break;
		}
		//printf("%lld\n",t.first);
	}
	
	printf("%lld\n",ans);
	return 0; 
}/*
4  4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
