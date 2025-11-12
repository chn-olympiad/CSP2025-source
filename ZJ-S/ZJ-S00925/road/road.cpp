#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct node{
	int x,y,z;
}a[1000002];
bool flag[100002];
bool cmp(const node &x,const node &y){
	return x.z<y.z;
}
int fa[10002],cnt[10002];
int c[12];
int v[12][10002];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int fx,int fy){
	fa[fx]=fy;
	cnt[fy]+=cnt[fx];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&v[i][j]);
	}
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)
//		printf("%d ",a[i].z);
	if(k==0){
		for(int i=1;i<=n;i++)
			fa[i]=i,cnt[i]=1;
		for(int i=1;i<=m;i++){
			if(cnt[1]==n)	break;
			int fx=find(a[i].x),fy=find(a[i].y);
			if(fx==fy)	continue;
			ans+=a[i].z;
			merge(fx,fy);
		}
		printf("%lld",ans);
	}
	for(int i=1;i<=n;i++)
		fa[i]=i,cnt[i]=1;
	for(int i=1;i<=m;i++){
		if(cnt[1]==n)	break;
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)	continue;
		int cnt=a[i].z;
		for(int j=1;j<=k;j++)
			if(v[j][a[i].x]+v[j][a[i].y]+(flag[j]==true?0:c[j])<a[i].z)
				cnt=v[j][a[i].x]+v[j][a[i].y]+(flag[j]==true?0:c[j]),flag[j]=false;
		ans+=cnt;
		merge(fx,fy);
	}
	printf("%lld",ans);
	return 0;
}

