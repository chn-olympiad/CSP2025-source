#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 2e6 + 5;

int n, m, k;
struct edge {
	int to, nxt, w;
} E[M * 2];
int cnt;
int head[N+15];
int a, b, c;
long long ans=0x3fffffffffffffff;
int vis[N+10];
bool is[N+10];
int w[15];
struct node{
	int i,w;
};
bool operator<(node _a,node _b){
	return _a.w>_b.w;
}

void addedge(int _a, int _b, int _w) {
	E[++cnt].to = _b;
	E[cnt].w = _w;
	E[cnt].nxt = head[_a];  
	head[_a] = cnt;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);
		addedge(b, a, c);
	}
	for(int i=0;i<k;i++){
		scanf("%d", &w[i]);
		for(int j=1;j<=n;j++){
			scanf("%d", &a);
			addedge(n+i+1,j,a);
			addedge(j,n+i+1,a);
		}
	}
	for(int S =0; S<(1<<k);S++){
		long long _ans=0;
		for(int i=0;i<k;i++){
			if((S>>i)&1)_ans+=w[i];
		}
		memset(vis,-1,sizeof(vis));
		memset(is,0,sizeof(is));
		priority_queue<node> q;
		q.push((node){1,0});
		node t;
		while(q.size()){
			t=q.top();
			q.pop();
			if(is[t.i])continue;
			is[t.i]=1;
			_ans+=t.w;
			if(_ans>ans){
				_ans=0x3fffffffffffffff;
				break;
			}
			for(int i=head[t.i];i;i=E[i].nxt){
				if(is[E[i].to])continue;
				if((E[i].to>n)&&(!(S>>(E[i].to-n-1)&1)))continue;
				if((vis[E[i].to]!=-1)&&(E[i].w>=vis[E[i].to]))continue;
				q.push((node){E[i].to,E[i].w});
				vis[E[i].to]=E[i].w;
			}
		}
		ans=min(ans,_ans);
	}
	printf("%lld",ans);
	return 0;
}
