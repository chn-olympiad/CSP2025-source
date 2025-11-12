#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10010],a[20][10010],c[20],ecnt,mxe;
struct node{int x,y,w;}e[1000010],E[10010],E2[10010];
long long ans;
inline bool cmp(node x,node y) {return x.w<y.w;}
inline int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f==1?x:-x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].w=read();
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}  
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy) f[fx]=fy,E[++ecnt]=e[i],mxe=max(mxe,e[i].w),ans+=e[i].w;
		if(ecnt==n-1) break;
	}
	for(int i=1;i<(1<<k);i++)
	{
		long long nowans=0,nowans2=0;
		int nowe=0,p=0,bo;
		for(int j=1;j<=k;j++) if(i&(1<<(j-1)))
		{
			bo=1;nowans+=c[j];nowans2+=c[j];
			int mn=1000000001;
			if(nowans2>=ans) break;
			for(int l=1;l<=n;l++) if(a[j][l]<=mxe) p+=bo,bo=0,E2[++nowe]=(node){n+j,l,a[j][l]},mn=min(mn,a[j][l]);
			nowans2+=mn;
		}
		if(nowans2>=ans) continue;
		sort(E2+1,E2+nowe+1,cmp);
		for(int j=1;j<=n+k;j++) f[j]=j;
		int nowchoose=0,l1=1,l2=1;
		while(l1<=ecnt||l2<=nowe)
		{
			node _e;
			if(l1>ecnt) _e=E2[l2],l2++;
			else if(l2>nowe) _e=E[l1],l1++;
			else if(E2[l2].w<E[l1].w) _e=E2[l2],l2++;
			else _e=E[l1],l1++;
			int fx=find(_e.x),fy=find(_e.y);
			if(fx!=fy) f[fx]=fy,nowans+=_e.w,nowchoose++;
			if(nowans>=ans||nowchoose==n+p-1) break;
		} 
		if(nowans<ans&&nowchoose==n+p-1) ans=nowans;  
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//100
