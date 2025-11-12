#include<bits/stdc++.h>
#define int long long
#define mp(a,b) make_pair(a,b)
using namespace std;

inline int read(){
	int a=0,b=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	b=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<1)+(a<<3)+(c-'0');
		c=getchar();
	}
	return a*b;
}
inline void write(int x){
	if(x<0)	putchar('-'),x=-x;
	if(x>=10)	write(x/10);
	putchar(x%10+48);
}
inline void write1(int x){
	write(x),putchar(' ');
}
inline void write2(int x){
	write(x),putchar('\n');
}

int n,m,k;
int c[20];
int a[20][20005];
struct node{
	int u,v,w;
	int cho;	//代表以后计算时 要保留  
	friend bool operator <(node a,node b){
		return a.w<b.w;
	}
}edge[1919810];

struct node2{
	int u,v,w;
	friend bool operator <(node2 a,node2 b){
		return a.w<b.w;
	}
}edge2[114514];	//注意这里边数急剧减少了！
int idx2;

struct node3{
	int u,v,w;
	friend bool operator <(node3 a,node3 b){
		return a.w<b.w;
	}
}edge3[114514];
int idx3; 

int fa[20005];	//因为只有这么多点！ 
inline int find(int u){
	if(fa[u]==u)	return u;
	return fa[u]=find(fa[u]);
} 
int cho[20];
int include13=1e17;	//极大值 
int include13_fAKe=1e17; 
void sol(){
//	cout<<"谭总的世界-007"<<endl;
	include13=0;
	idx3=0;
	for(int i=1;i<=idx2;i++){
		edge3[++idx3].u=edge2[i].u,edge3[idx3].v=edge2[i].v,edge3[idx3].w=edge2[i].w;
	}
	int sum_=n;
	for(int i=1;i<=k;i++){
		if(!cho[i])	continue;
		include13+=c[i];
		for(int j=1;j<=n;j++){
			edge3[++idx3].u=i+n,edge3[idx3].v=j,edge3[idx3].w=a[i][j];
		}
		sum_++;
	}
//	for(int i=1;i<=idx3;i++){
//		cout<<'%'<<i<<' '<<edge3[i].u<<' '<<edge3[i].v<<' '<<edge3[i].w<<endl;
//	}
//	cout<<endl;
	for(int i=1;i<=n+k;i++){
		fa[i]=i; 
	}
	stable_sort(edge3+1,edge3+idx3+1);
	int sum=0;
	for(int i=1;i<=idx3;i++){
		int u=edge3[i].u,v=edge3[i].v,w=edge3[i].w;
		u=find(fa[u]),v=find(fa[v]);
		if(u!=v){
			fa[u]=v,include13+=w;
			sum++;
		}
		if(sum==sum_-1)	break; 
	}
//	cout<<include13<<endl<<endl;
	include13_fAKe=min(include13_fAKe,include13);
	return;
}
void dfs(int u){
	if(u==k+1){
		sol();
		return;
	}
	cho[u]=1,dfs(u+1);
	if(c[u]!=0)	cho[u]=0,dfs(u+1);
	return;
} 
#undef int
int main(){
	#define int long long 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
		edge[i].cho=0;
	}
	stable_sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	} 
	int sum=0;
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		u=find(fa[u]),v=find(fa[v]);
		if(u!=v){
//			cout<<'!'<<u<<' '<<v<<' '<<w<<endl; 
			edge[i].cho=1;
//			edge2[++idx2]=(node2){edge[i].u,edge[i].v,w};
			edge2[++idx2].u=edge[i].u,edge2[idx2].v=edge[i].v,edge2[idx2].w=edge[i].w;
			fa[u]=v;	//这就是最重要的一步！  
			sum++;
		}
		if(sum==n-1)	break;
	}
//	cout<<'^'<<idx2<<endl;
//	cout<<"谭总的世界-031"<<endl;
//	return 0; 
//	cout<<"谭总的世界-070"<<endl;
//	cout<<idx2<<endl;
//	for(int i=1;i<=idx2;i++){
//		cout<<edge2[i].u<<' '<<edge2[i].v<<' '<<edge2[i].w<<endl;
//	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
//	cout<<"谭总的世界-031"<<endl; 
//	return 0;
	dfs(1);	//暴力枚举所有的点 选还是不选 
	write2(include13_fAKe);
	return 0; 
} //CSP-S 2025 RP++ 