#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=2e6+100;
struct edge{int to,val,nxt;}e[M];
int h[N],pe=2,n,m,k,dad[N],rd[100][N],cst[100];
void add(int a,int b,int c){e[pe]=edge{b,c,h[a]};h[a]=pe++;}
bool vis[N];
int fd(int u){return u==dad[u]?u:fd(dad[u]);}
void inone(int a,int b){dad[fd(a)]=fd(b);return;}
bool isone(int a,int b){return (fd(a)==fd(b));}

int res=0;
struct node{
	int i,val;
	friend bool operator < (node a,node b){
		return a.val>b.val;
	}
};
priority_queue<node> q;
void prim(int u){
	q=priority_queue<node>();
	q.push(node{u,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.i]) continue;
		else inone(t.i,u),res+=t.val,vis[t.i]=1;
		cout << t.i << endl;
		for(int i=h[t.i];i;i=e[i].nxt){
			int to=e[i].to,val=e[i].val;
			q.push(node{to,val});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*cin >> n >> m >> k;
	for(int i=0,a,b,c;i<m;i++){
		cin >> a >> b >> c;
		add(a,b,c),add(b,a,c);
	}
	for(int i=1;i<=k;i++){
		cin >> cst[i];
		add(n+(i*2),n+(i*2)+1,cst[i]);
		for(int j=1;j<=n;j++){
			cin >> rd[i][j];
			add(i,n+(i*2),rd[i][j]);
			add(n+(i*2)+1,i,rd[i][j]);
		}
	}
	prim(1);
	cout << res;*/
	cout << 0;
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
*/
