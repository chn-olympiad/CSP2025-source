#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=0;
	while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c&15);c=getchar();}
	return x*f;
}
int n,nn,m,k,a[20],cnt,f[10100],siz[10100],res,ans;
struct node{
	int u,v,w;
}mp[1001000],mp2[1001000],all[1000010],qp[20][10100];
bool cmp(node a,node b){
	return a.w<b.w;
}
void build(){
	for(int i=1;i<=n;i++){
		f[i]=i;
		siz[i]=1;
	}
}
int Find(int x){
	if(f[x]==x)	return x;
	return f[x]=Find(f[x]);
}
void Merge(int x,int y,int w){
	int fx=Find(x),fy=Find(y);
	if(fx==fy)	return ;
	if(siz[fx]>siz[fy])
		swap(fx,fy);
	f[fx]=fy;
	siz[fy]+=siz[fx];
	ans+=w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		mp[i].u=read(),mp[i].v=read(),mp[i].w=read();
	sort(mp+1,mp+m+1,cmp);
	build(); 
	for(int i=1;i<=m;i++){
		int fx=Find(mp[i].u),fy=Find(mp[i].v);
		if(fx!=fy){
			Merge(mp[i].u,mp[i].v,mp[i].w);
			mp[++cnt]=mp[i];
		}
	}
	res=ans;
	for(int i=0;i<k;i++){
		a[i]=read();
		int root=1;
		for(int j=1;j<=n;j++){
			qp[i][j].w=read();
			if(qp[i][j].w<qp[i][root].w)
				root=j;
		}
		a[i]+=qp[i][root].w;
		for(int j=1;j<=n;j++)
			qp[i][j].u=root,qp[i][j].v=j;
		sort(qp[i]+1,qp[i]+n+1,cmp);
	}
	for(int i=1;i<(1<<k);i++){
		build();
		for(int i=1;i<n;i++)
			all[i]=mp[i];
		ans=0,cnt=n-1;
		for(int j=0;j<k;j++)
			if(i>>j&1){
				ans+=a[j];
				int x=1,y=1,noww=0;
				while(x<=cnt&&y<=n){
					if(all[x].w<qp[j][y].w)
						mp2[++noww]=all[x++];
					else mp2[++noww]=qp[j][y++];
				}
				while(x<=cnt)
					mp2[++noww]=all[x++];
				while(y<=n)
					mp2[++noww]=qp[j][y++];
				cnt=noww;
				for(int i=1;i<=cnt;i++)
					all[i]=mp2[i];
			}
		for(int i=1;i<=cnt;i++){
			Merge(all[i].u,all[i].v,all[i].w);
			if(ans>=res)	break;
		}
		res=min(res,ans);
	}
	cout<<res;
	return 0;
}


