#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int mp[12][N];
inline int read()
{
	int x=1,s=0;
	char ch=getchar();
	while(ch<'0'&&ch>'9')x=-1,ch=getchar();
	
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return x*s;
}
struct NODE{
	int x;
	int y;
	int z;
}e[M];
NODE q[N*10];
int fa[N+10];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(NODE x,NODE y){
	return x.z<y.z;
}
int val[N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen()
	int n,m,k;
	//scanf("%d%d%d",&n,&m,&k);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].x=read();e[i].y=read();e[i].z=read();
		//scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		val[i]=read();
//		scanf("%d",&val[i]);
		for(int j=1;j<=n;j++){
			mp[i][j]=read();
			//scanf("%d",&mp[i][j]);
		}
	}
	ll ans=1e18;
	for(int v=0;v<(1<<k);v++){
	//	if(v==0)continue;
		ll s=0;
		int tot=0;
		int pl=0;
		for(int i=1;i<=n+10;i++)fa[i]=i;
		for(int j=1;j<=k;j++){
			if((v>>(j-1))&1){
				s=s+val[j];
				pl++;
			//	printf("K:%d\n",j);
				for(int i=1;i<=n;i++){
					q[++tot].x=i;
					q[tot].y=j+n;
					q[tot].z=mp[j][i];
				}				
			}
		}
		sort(q+1,q+tot+1,cmp);
		int nw1=1,nw2=1;
		int cnt=0,flg=0;
		while(nw1<=m&&nw2<=tot){
			int x,y,xx,yy;
			while(e[nw1].z<q[nw2].z&&nw1<=m){
				x=e[nw1].x;
				y=e[nw1].y;
				xx=find(x),yy=find(y);
				if(xx!=yy){
					fa[xx]=yy;
			//		printf("%d %d %d\n",e[nw1].x,e[nw1].y,e[nw1].z);
					s+=e[nw1].z;
					++cnt;
				}
				++nw1;
				if(cnt==n+pl-1){flg=1;break;}
			}
			if(flg==1)break;
			x=q[nw2].x;
			y=q[nw2].y;
			xx=find(x),yy=find(y);
			if(xx!=yy){
				fa[xx]=yy;
				s+=q[nw2].z;
			//	printf("%d %d %d\n",q[nw2].x,q[nw2].y,q[nw2].z);
				cnt++;
				if(cnt==n+pl-1){flg=1;break;}
			}
			++nw2;
		}
		if(flg==1){
			ans=min(ans,s);
		//	printf("%d %d %d\n",v,s,cnt); 
			continue;
		}
		while(nw2<=tot){
			int x=q[nw2].x;
			int y=q[nw2].y;
			int xx=find(x);
			int yy=find(y);
			if(xx!=yy){
				fa[xx]=yy;
				s+=q[nw2].z;
		//		printf("%d %d %d\n",q[nw2].x,q[nw2].y,q[nw2].z);
				cnt++;
				if(cnt==n+pl-1)break;
			}
			++nw2;
		}
		while(nw1<=m){
			int x=e[nw1].x;
			int y=e[nw1].y;
			int xx=find(x),yy=find(y);
			if(xx!=yy){
				fa[xx]=yy;
				s+=e[nw1].z;
			//	printf("%d %d %d\n",e[nw1].x,e[nw1].y,e[nw1].z);
				cnt++;
				if(cnt==n+pl-1)break;
			}
			++nw1;
		}
		ans=min(ans,s);
	//	printf("%d %d %d\n",v,s,cnt); 
	}
	printf("%lld",ans);
	return 0;
}
