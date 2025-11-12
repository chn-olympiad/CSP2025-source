#include<bits/stdc++.h>
//T2
//k=0 最小生成树 
using namespace std;
const int N=1e6*2+100;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,k;
struct edge{
	int u,v,w;
}a[N];
bool cmp(edge aa,edge bb){
	return aa.w<bb.w;
}
int fa[N],e[15][N],c[15];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void sub1(){
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		ans+=w;
		cnt++;
		fa[fu]=fv;
		if(cnt==n-1)break;
	}
	cout<<ans<<"\n";
	return;
}
void sub2(){
	int num=m;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			num++;
			if(e[i][j]==0)a[num].u=i+n,a[num].v=j,a[num].w=0;
			else a[num].u=i+n,a[num].v=j,a[num].w=e[i][j];
		}
	}
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int cnt=0,ans=0;
	for(int i=1;i<=num;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		ans+=w;
		cnt++;
		fa[fu]=fv;
		if(cnt==n+k-1)break;
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	if(k==0){
		sub1();
		return 0;
	}
	bool fl=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])fl=1;
		for(int j=1;j<=n;j++){
			e[i][j]=read();
		}
	}
	if(fl==0){
		sub2();
		return 0;
	}
	return 0;
}
