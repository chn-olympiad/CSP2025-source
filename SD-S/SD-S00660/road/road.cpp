#include <bits/stdc++.h>
#define ll long long 
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define endl '\n'
#define _x putchar('\n')
using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}

const int M = 1e6+10,N = 1e4+100;

int n = 0,m = 0,k = 0,fa[N],cnt = 0,c[30];
struct node{
	int x,y,w,id;
}a[M+20*N];
int findf(int x){
	return fa[x] == x?x:fa[x] = findf(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int mp[20][N];
ll sum = 0;
void kru(int s){
	
	int tot = 0,count = 0;
	memset(fa,0,sizeof fa);
	for(int i = 1;i<=n+k;++i){
		fa[i] = i;
	}
	int t = s;
	while(t){
		if(s%2 == 1) ++count;
		t>>=1;
	}
	//总共有 m + k*n 条边 
	for(int i = 1;i<=cnt;++i){
		
		if(a[i].x > n){//是新加的点 
			int p = a[i].x-n;
			if(((1<<p>>1)&s) == 0)continue;
		}
		int fx = findf(a[i].x),fy = findf(a[i].y);		
		if(fx == fy)continue;
		fa[fx] = fy;
		
		sum += a[i].w;
		
		++tot;
		if(tot == n-1+count)break;
	}
	
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	rep(i,1,m){
		int u = 0,v = 0,w = 0;
		read(u);read(v);read(w);
		a[++cnt].x = u;
		a[cnt].y = v;
		a[cnt].w = w;
		a[cnt].id = cnt;
	}
	rep(i,1,k){
		read(c[i]);
		for(int j = 1;j<=n;++j){
			read(mp[i][j]);
			a[++cnt].x = i+n;
			a[cnt].y = j;
			a[cnt].w = mp[i][j];
			a[cnt].id = cnt;
		}
	}
	if(k == 0){
		kru(0);
		cout <<sum<<endl;
		return 0;
	}
	
	sort(a+1,a+1+cnt,cmp);
	int U = (1<<k)-1;
	ll ans = 0x7f7f7f7f7f7f7f7f;
	for(int s = 0;s<=U;++s){
		sum = 0;
		for(int i = 1;i<=k;++i){
			if(((1<<(i-1))&s) != 0){
				sum += c[i];
			}
		}
		kru(s);
		ans = min(ans,sum);
	}
	
	cout <<ans;
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

6 7 3
1 2 10
2 4 20
2 3 30
1 3 5
100 0 0 0 0
20 0 0 0 0
10 0 0 0 0

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
