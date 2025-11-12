#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct sd{
	int x,y,z;
}ed[2000005],s[2000005];
ll ans=1e18;
int n,m,k,a[15][10005],c[15],fa[20005],usd[20005],v[15];
int find(int x){
	if(x==fa[x])	return x;
	return fa[x]=find(fa[x]);
}
bool cmp(sd x,sd y){
	return x.z<y.z;
}
void dfs(int step){
	if(step==k+1){
		for(int i=1;i<=m;i++){
			s[i]=ed[i];
			if(i<=n)	fa[i]=i,usd[i]=1;
		}
		for(int i=m+1;i<=n;i++)	fa[i]=i,usd[i]=1;
		int tt=m;
		ll cnt=0;
		for(int i=1;i<=k;i++){
			if(v[i]!=1)	continue;
			cnt+=c[i];
			usd[i+n]=0;
			fa[i+n]=i+n;
			for(int j=1;j<=n;j++){
				s[++tt]={i+n,j,a[i][j]};
			}
		}
		int num=0;
		sort(s+1,s+tt+1,cmp);
		for(int i=1;i<=tt;i++){
			int dx=find(s[i].x),dy=find(s[i].y);
			if(dx==dy)	continue;
			fa[dx]=dy;
			cnt+=s[i].z;
			if((++usd[s[i].x])!=1 && (++usd[s[i].y])!=1)num++;
			if(num==n-1)	break;
		}
		ans=min(ans,cnt);
		return ;
	}
	if(v[step]==-1)	dfs(step+1);
	else
		for(int i=0;i<=1;i++){
			v[step]=i;
			dfs(step+1);
		}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&ed[i].x,&ed[i].y,&ed[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		int flag=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)	flag=j;
//			if(!c[i])	ed[++m]={n+i,j,a[i][j]};
		}
		if(flag && !c[i]){
			v[i]=-1;
			for(int j=1;j<=n;j++){
				if(j==flag)	continue;
				ed[++m]={flag,j,a[i][j]};
			}
		}
	}
	dfs(1);
	printf("%lld",ans);
}