#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c=getchar();int x=0;bool f=0;
	while(c>'9'||c<'0'){
		if(c=='-')f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(f)return -x;
	return x;
}
int n,m,k,fa[20005],id,u[10005],v[10005],w[10005],b[15][10005],cnt,c[15],ans;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct P{
	int u,v,w;
}a[1000005];
bool cmp(P a,P b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			fa[find(a[i].u)]=find(a[i].v);
			id++;
			u[id]=a[i].u,v[id]=a[i].v,w[id]=a[i].w;
			ans+=a[i].w;
		}
	}
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)b[i][j]=read();
	}
	for(int i=1;i<(1<<k);i++){
		cnt=0;
		for(int j=1;j<=id;j++)cnt++,a[cnt].u=u[j],a[cnt].v=v[j],a[cnt].w=w[j];
		int res=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i){
				res+=c[j];
				for(int p=1;p<=n;p++)cnt++,a[cnt].u=n+j+1,a[cnt].v=p,a[cnt].w=b[j][p];
			}
		}
		if(res>=ans)continue;
		sort(a+1,a+cnt+1,cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=cnt;i++){
			if(find(a[i].u)!=find(a[i].v)){
				fa[find(a[i].u)]=find(a[i].v);
				res+=a[i].w;
				if(res>=ans)break;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
