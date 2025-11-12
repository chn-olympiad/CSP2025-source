#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,m,k;
struct road{
	int from,to,date;
};
road a[N];
bool cmp(road a,road b){
	return a.date<b.date;
}
struct bcj{
	int fa;
}vis[N];
int find(int u){
	if(vis[u].fa==u){
		return u;
	}
	vis[u].fa=find(vis[u].fa);
	return vis[u].fa;
}
long long zxs(){
	long long sum=0;
	int len=m+n*k;
	for(int i=0;i<len;i++){
		int f=find(a[i].from),t=find(a[i].to);
		if(f==t){
			continue;
		}
		vis[f].fa=vis[t].fa;
		sum+=a[i].date;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int alen=0;
	for(int i=1;i<=n+k;i++){
		vis[i].fa=i;
	}
	for(int i=1;i<=n;i++){
		int f,t,d;
		scanf("%d %d %d",&f,&t,&d);
		a[i].from=f;
		a[i].to=t;
		a[i].date=d;
		alen+=1;
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		int d;
		for(int j=1;j<=n;j++){
			scanf("%d",&d);
			alen++;
			int x=alen;
	 		a[x].from=n+i;
			a[x].to=j;
			a[x].date=d;
		}	
	}
	sort(&a[1],&a[alen+1],cmp);
	
	printf("%lld",zxs());
	return 0;
} 
