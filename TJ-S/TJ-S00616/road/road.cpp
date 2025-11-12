#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define M 1000005
#define int long long 
int n,m,k;
struct edge{
	int u;
	int v;
	int w;
}e[M];
int ans;
int cnt;
int father[N];
void make(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}
int find(int a){
	if(father[a]!=a){
		father[a]=find(father[a]);
	}
	return father[a];
}
void merge(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		father[x]=y;
	}
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void kru(){
	make(n);
	int ce=0;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		//cout<<e[i].w<<' ';
		if(ce==n-1){
			return;
		}
		int a=e[i].u;
		int b=e[i].v;
		int s=e[i].w;
		int x=find(a);
		int y=find(b);
		if(x!=y){
			merge(x,y);
			ans+=s;
			ce++;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,s;
		cin>>a>>b>>s;
		cnt++;
		e[cnt].u=a;
		e[cnt].v=b;
		e[cnt].w=s;
		cnt++;
		e[cnt].u=b;
		e[cnt].v=a;
		e[cnt].w=s;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	kru();
	cout<<ans;
	return 0;
}
