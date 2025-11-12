#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[20][20005],c[25],flag[20005],bian[1005][1005];
long long head[2000005],Next[2000005],ver[2000005],we[2000005],tot;
void add(int s,int t,int q){
	ver[++tot]=t;
	Next[tot]=head[s];
	we[tot]=q;
	head[s]=tot;
}
long long ans;
struct node{
	int u,v,w;
}b[2000005],zui[2000005];
bool cmp(node e,node r){
	return e.w<r.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bian[i][j]=1e16+7;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
		bian[b[i].u][b[i].v]=b[i].w;
	}
	int flag1=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0){
			flag1=1;
		}
		//cout<<c[i]<<" ";
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			//cout<<a[i][j]<<" ";
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				bian[j][k]=min(bian[j][k],a[i][j]+a[i][k]+c[i]);
				//cout<<bian[j][k]<<"\n";
			}
		}
		//cout<<"\n";
	}
	if(k==0){
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(flag[b[i].u]==0){
				ans+=b[i].w;
				flag[b[i].u]=1;
				flag[b[i].v]=1;
			}
			else if(flag[b[i].v]==0){
				ans+=b[i].w;
				flag[b[i].v]=1;
				flag[b[i].u]=1;
			}
		}
		printf("%lld\n",ans);
	}
	else{
		int cnt=0;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(bian[i][j]!=0){
					//cout<<i<<" "<<j<<" "<<bian[i][j]<<"\n";
					zui[++cnt].u=i;
					zui[cnt].v=j;
					zui[cnt].w=bian[i][j];
				}
			}
		}
		sort(zui+1,zui+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(flag[zui[i].u]==0){
				ans+=zui[i].w;
				flag[zui[i].u]=1;
				flag[zui[i].v]=1;
			}
			else if(flag[zui[i].v]==0){
				ans+=zui[i].w;
				flag[zui[i].v]=1;
				flag[zui[i].u]=1;
			}
			cout<<zui[i].u<<" "<<zui[i].v<<" "<<zui[i].w<<"\n";
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
