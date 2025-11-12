#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,quan,id=0;
}a[2000005];
int cheng[10005];
int f[10005];
bool cmp(node x,node y){
	return x.quan<y.quan;
}
bool vis[10005]; 
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void mag(int x,int y){
	f[x]=f[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].quan);
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&cheng[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			a[++cnt].x=i+n;
			a[cnt].y=j;
			a[cnt].quan=x;
			a[cnt].id=1;
		} 
	}
	sort(a+1,a+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++){
//		printf("%d %d %d\n",a[i].x,a[i].y,a[i].quan);
//	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int v=0;v<=k;v++){
		int cc=0;
		long long lin=0;
		for(int i=1;i<=v;i++){
			lin+=cheng[i];
		}
		for(int i=1;i<=n+v;i++){
			f[i]=i;
		}
		for(int i=1;i<=cnt;i++){
			if(cc==n-1+v){
				break;
			}
			int x=a[i].x;
			int y=a[i].y;
			int fx=find(x);
			int fy=find(y);
			if(fx==fy){
				continue;
			}
			if(a[i].id==0){
				cc++;
				lin+=a[i].quan;
				mag(fx,fy);
				if(v==k){
//					printf("%d %d %d\n",a[i].x,a[i].y,cc);
				}
			}
			else{
				if(a[i].x>v+n){
					continue;
				}
				else{
					cc++;
					lin+=a[i].quan;
					mag(fx,fy);
					if(v==k){
//						printf("%d %d %d\n",a[i].x,a[i].y,cc);
					}
				}
			}
		}
//		printf("%lld\n",lin);
		ans=min(ans,lin);
	}
	printf("%lld",ans);
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
