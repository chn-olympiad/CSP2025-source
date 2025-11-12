#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=(int)1e6+10;
const int maxm=(int)1e6+10;
inline ll read(){
	ll x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(int)(c-'0');
		c=getchar();
	}
	return x*w;
}
inline void print(ll x){
	char s[20];
	int top=0;
	if(x==0){
		putchar('0');
		return ;
	}
	if(x<0){
		x=-x;
		putchar('-');
	}
	while(x){
		top++;
		s[top]=(char)(x%10+'0');
		x/=10;
	}
	while(top){
		putchar(s[top]);
		top--;
	}
}
int fa[maxm];
inline int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void hang(int l1,int l2){
	fa[find(l1)]=find(l2);
} 
int n,m,k,sum,cnt;
//struct edge{
//	int nxt,to,w;
//	edge(int _n=0,int _t=0,int _w=0):nxt(_n),to(_t),w(_w){}
//}e[maxn];
//int head[maxm],num_edge;
//inline void add(int from,int to,int w){
//	num_edge++;
//	e[num_edge]=edge(head[from],to,w);
//	head[from]=num_edge;
//}
struct edge{
	int u,v,w;
	edge(int x=0,int y=0,int we=0):u(x),v(y),w(we){}
};
inline bool cmp(edge x,edge y){
	return x.w>y.w;
}
vector<edge> e;
void Kruskal(){
	sort(e.begin(),e.end(),cmp);
	int s=e.size();
	for(int i=1;i<=s;i++){
		edge tem=e.back();
		e.pop_back();
		if(find(tem.u)==find(tem.v))continue;
		hang(fa[tem.u],fa[tem.v]);
		sum+=tem.w;
		cnt++;
		if(cnt==n-1){
			return ;
		}
	}
}
int arr[maxn];
map<pair<int,int> ,int>f;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();
		v=read();
		w=read();
		e.push_back(edge(u,v,w));
		e.push_back(edge(v,u,w));
		f[make_pair(u,v)]=f[make_pair(v,u)]=w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		int tem=read();
		for(int i=1;i<=n;i++){
			arr[i]=read();
			for(int j=1;j<i;j++){
				if(!f[make_pair(i,j)]||f[make_pair(i,j)]>tem+arr[i]+arr[j]){
//					e.erase(edge(i,j,f[make_pair(i,j)]));
//					e.erase(edge(j,i,f[make_pair(j,i)]));
					e.push_back(edge(i,j,arr[i]+tem+arr[j]));
					e.push_back(edge(j,i,arr[i]+tem+arr[j]));
					f[make_pair(i,j)]=f[make_pair(j,i)]=arr[i]+tem+arr[j];
				}
			}
		} 
	}
	Kruskal();
	print(sum);
	fclose(stdin);
	fclose(stdout);
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
