#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=2e5+5;
int n,m,k,c[15],ff[N],fa[N],ans;
struct node{
	int u,v,f;
}a[N];
bool cmp(node x,node y){
	return x.f<y.f;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		a[i].u=read(),a[i].v=read(),a[i].f=read();
	}
	int y=n;
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j){
			ff[j]=read();
		}
		for(int j=1;j<=n;++j){
			for(int l=j+1;l<=n;++l){
				y++;
				a[y].u=j,a[y].v=l,a[y].f=ff[j]+ff[l];
			}
		}
	}
	sort(a+1,a+1+y,cmp);
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=y;++i){
		int l=(int)(a[i].u);
		int r=(int)(a[i].v);
		int fu=find(l),fv=find(r);
		if(fu==fv){
			continue;
		}
		fa[fu]=fv;
		ans+=a[i].f;
	}
	cout<<ans;
	return 0;
}
