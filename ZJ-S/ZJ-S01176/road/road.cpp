#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,cnt,tot,fl=1;
int n,m,k;
struct S{
	int u,v,w;
}biann[1500006],bian[1500006],xb[20006],fb[15][200006];
bool cmp(S a,S b){
	return a.w<b.w;
}
vector<pair<int,int> >e[20005];
int fa[200005];
struct SS{
	int x,id;
}a[15][20005];
struct SSS{
	int val,i,j,f;
	friend bool operator<(SSS a,SSS b){
		return a.val>b.val;
	}
};
bool cmp2(SS a,SS b){
	return a.x<b.x;
}
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&bian[i].u,&bian[i].v,&bian[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&a[i][j].x);
			a[i][j].id=j;
		}
		int num=0;
		sort(a[i]+1,a[i]+n+1,cmp2);
		for(int j=2;j<=n;j++){
			fb[i][++num]={a[i][1].id,a[i][j].id,a[i][j].x+a[i][1].x};
		}
	}
	sort(bian+1,bian+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=bian[i].u,y=bian[i].v;
		int xx=fd(x),yy=fd(y);
		if(xx!=yy){
			fa[xx]=yy;ans+=bian[i].w;
			xb[++tot]={x,y,bian[i].w};
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	ans=1e18;
	for(int st=0;st<(1<<k);st++){
		tot=0;cnt=0;
		for(int i=1;i<=n-1;i++){
			biann[++tot]=xb[i];
		}
		for(int i=1;i<=k;i++){
			if((st>>(i-1))&1){
				cnt=cnt+a[i][0].x;
				for(int j=1;j<=n-1;j++){
					biann[++tot]=fb[i][j];
				}
			}
		}
		sort(biann+1,biann+tot+1,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		int num=0;
		for(int i=1;i<=tot;i++){
			int x=biann[i].u,y=biann[i].v;
			int xx=fd(x),yy=fd(y);
			if(xx!=yy){
				fa[xx]=yy;
				cnt=cnt+biann[i].w;
				num++;
				if(num==n-1){
					continue;
				}
			}
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}

