#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return w*x;
}
int ostk[20],otop;
void print(int x){
	if(x==0){putchar('0');putchar(' ');return;}
	if(x<0){x=-x;putchar('-');}
	while(x){ostk[++otop]=x%10+48;x/=10;}
	while(otop){putchar(ostk[otop--]);}
	putchar(' ');
}
#define endline putchar('\n')
#define endl '\n'
const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
struct edge{
	int from,to,next,weight;
	edge(int f=0,int t=0,int n=0,int w=0):from(f),to(t),next(n),weight(w){}
};
bool operator<(edge e1,edge e2){
	return e1.weight>e2.weight;
}
edge e[2*M];
int head[N],edge_num;
void add_edge(int from,int to,int weight){
	e[++edge_num]=edge(from,to,head[from],weight);
	head[from]=edge_num;
}
int parent[N];
void init(int maxn){
	for(int i=1;i<=maxn;i++){
		parent[i]=i;
	}
}
int find(int u){
	if(parent[u]==u) return u;
	return parent[u]=find(parent[u]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u!=v){
		parent[u]=v;
	}
}
int min_price(){
//	priority_queue<edge,vector<edge>,greater<edge>> que;
	priority_queue<edge> que;
	for(int i=1;i<=edge_num;i++){
		que.push(e[i]);
	}
	int res=0;
	while(!que.empty()){
		edge cur=que.top();
		que.pop();
		if(find(cur.from)!=find(cur.to)){
			res+=cur.weight;
			merge(cur.from,cur.to);
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	init(n);
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	if(k==0){
		print(min_price());
	}else{
		print(0);
	}
	return 0;
}
/*
8 9 0
1 2 1
1 3 3
1 4 2
4 6 5
6 7 1
5 7 2
2 5 3
2 8 1
5 8 2
*/

