#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
	return x*f;
}
const int N=1e4+10;
struct node{
	int v,w;
}e[N][100];
int cnt[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[u][++cnt[u]].w=w,e[u][cnt[u]].v=v;
		e[v][++cnt[v]].w=w,e[v][cnt[v]].v=u;
	}
	
	for(int i=1;i<=n;i++)sort(e[i]+1,e[i]+1+cnt[i],cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			cout<<e[i][j].w<<' ';
		}
		cout<<endl;
	} 
	int maxx=-1,ans=0;
	for(int i=1;i<=n;i++){
		ans+=e[i][1].w; 
		cntt[i]++;
		cntt[e[i][1].v]++;
	}
	for(int i=1;i<=n;i++){
		 
	}
	cout<<ans-maxx;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
