#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node{
	int x,y,z;
}q[N+100009],p[N+100009];
int c[20];
int a[20][10009];
int fa[10009];
bool cmp(node a,node b){
	return a.z<b.z;
}
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,f=0;
//	cin>>n>>m>>k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
//		cin>>p[i].x>>p[i].y>>p[i].z;
		q[i].x=p[i].x,q[i].y=p[i].y,q[i].z=p[i].z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])f=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int cnt=m,ans=1e18;
	if(f){
		for(int i=0;i<=(1<<k)-1;i++){
			cnt=m;int sum=0;
			for(int j=1;j<=m;j++){
				
				q[j].x=p[j].x,q[j].y=p[j].y,q[j].z=p[j].z;
	//			cout<<q[j].x<<' '<<q[j].y<<' '<<q[j].z<<'\n';
			}
			for(int j=1;j<=n+k;j++)fa[j]=j;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					sum+=c[j];
					for(int l=1;l<=n;l++){
						q[++cnt].x=n+j;q[cnt].y=l,q[cnt].z=a[j][l];
					}
				}
			}
			sort(q+1,q+1+cnt,cmp);
			for(int j=1;j<=cnt;j++){
				int x=get(q[j].x),y=get(q[j].y);
				if(x!=y){
	//				cout<<q[j].x<<' '<<q[j].y<<' '<<q[j].z<<'\n';
					sum+=q[j].z;
					fa[x]=y;
				}
			}
			ans=min(ans,sum);
		}
	}
	else{
		int sum=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=k;j++){
			sum+=c[j];
			for(int l=1;l<=n;l++){
				q[++cnt].x=n+j;q[cnt].y=l,q[cnt].z=a[j][l];
			}
		}
		sort(q+1,q+1+cnt,cmp);
		for(int j=1;j<=cnt;j++){
			int x=get(q[j].x),y=get(q[j].y);
			if(x!=y){
//				cout<<q[j].x<<' '<<q[j].y<<' '<<q[j].z<<'\n';
				sum+=q[j].z;
				fa[x]=y;
			}
		}
		ans=min(ans,sum);
	}
	printf("%d",ans);
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