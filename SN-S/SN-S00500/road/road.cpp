//王梓乔 SN-S00500 西安高新第一初级中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,k,m;
int c[15][100005];
struct pig2{
	int x,y,w;
}bian[2000005];int cnt;
inline bool cmp(pig2 a,pig2 b){return a.w<b.w;}
int fa[10005];
inline int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
inline void subtask1(){
	sort(bian+1,bian+m+1,cmp);
	for(int i=1;i<=n;i++)	fa[i]=i;
	int cntx=0,i=1,x,y,ans=0;
	while(cntx<n-1&&i<=m){
		x=find(bian[i].x),y=find(bian[i].y);
		if(x!=y)	fa[x]=y,cntx++,ans+=bian[i].w;
		i++;
	}
	cout<<ans<<'\n';
}
pig2 bianx[2000005];
int xxx;
inline int work(){
	for(int i=1;i<=cnt;i++)	bianx[i]=bian[i];
	sort(bianx+1,bianx+cnt+1,cmp);
	for(int i=1;i<=xxx;i++)	fa[i]=i;
	int cntx=0,i=1,x,y,ans=0;
	while(cntx<xxx-1&&i<=cnt){
		x=find(bianx[i].x),y=find(bianx[i].y);
		if(x!=y)	fa[x]=y,cntx++,ans+=bianx[i].w;
		i++;
	}
	return ans;
}
int ans=1e18;
inline void dfs(int now,int nowans){
	if(now>k){
		ans=min(ans,work()+nowans);
		return ;
	}
	dfs(now+1,nowans);
	if(nowans+c[now][0]>ans)	return ;
	xxx++;
	for(int i=1;i<=n;i++)	bian[++cnt].x=xxx,bian[cnt].y=i,bian[cnt].w=c[now][i];
	dfs(now+1,nowans+c[now][0]);
	cnt-=n,xxx--;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();cnt=m;
	xxx=n;
	for(int i=1,x,y,z;i<=m;i++){
		x=read(),y=read(),z=read();
		bian[i].x=x,bian[i].y=y,bian[i].w=z;
//		add(x,y,z),add(y,x,z);
	}
	int eeeeee=work();
	if(k==0){subtask1();return 0;}
	bool zdfdf=1;
	for(int i=1,fl;i<=k;i++){
		fl=1;
		for(int j=0;j<=n;j++){
			c[i][j]=read();
			if(c[i][j]!=0)	fl=0;
		}
		if(fl==1){puts("0");return 0;}
		if(c[i][0]<eeeeee)	zdfdf=0;
	}
	if(zdfdf==1){cout<<eeeeee<<'\n';return 0;}
	dfs(1,0);
	cout<<ans<<'\n';
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
