#include<bits/stdc++.h>
using namespace std;
int maxn;
struct p{
	int x,y,z;
}a[100005];
int n,t;
void dfs(int k,int xx,int yy,int zz,int sum){
	if(xx>n/2||yy>n/2||zz>n/2)return ;
	if(k==n+1){
		maxn=max(maxn,sum);
		return ;
	}
	dfs(k+1,xx+1,yy,zz,sum+a[k].x);
	dfs(k+1,xx,yy+1,zz,sum+a[k].y);
	dfs(k+1,xx,yy,zz+1,sum+a[k].z);
}
bool cmp(p aa,p bb){
	return aa.x>bb.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int tmp1=0,tmp2=0;
		maxn=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			tmp1+=a[i].y,tmp2+=a[i].z;
		}
		if(tmp1==0&&tmp2==0){
			long long ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			printf("%lld",ans);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%d\n",maxn);
	}
	return 0;
}
