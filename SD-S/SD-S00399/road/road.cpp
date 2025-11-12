#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long c[100025];
long long a[15][100025];
int fa[100025]; 
int vis[10005];
int pos=0;
struct node{
	int u,v;
	long long w;
}e[2000005],g[2000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find_fa(int u){
	return (fa[u]==u?u:fa[u]=find_fa(fa[u]));
}
long long check(int d,int O){
	for(int i=1;i<=d;i++)fa[i]=i;
	long long ans=0;
	sort(g+1,g+O+1,cmp);
	for(int i=1;i<=O;i++){
		int u=find_fa(g[i].u),v=find_fa(g[i].v);
		if(u!=v){
			if(g[i].u>n)pos++;
			fa[u]=v;
			ans+=g[i].w;
		}
		g[i]=e[i];
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
		g[i]=e[i];
	}
//	int flag=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
//		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
//	if(flag){
//		int sum=n,num=m;
//		for(int i=1;i<=k;i++){
//			sum++;
//			for(int j=1;j<=n;j++)g[++num]={sum,j,a[i][j]};
//		}
//		for(int i=1;i<=m;i++)g[i]=e[i];
//		cout<<check(sum,num);
//		return 0;
//	}
	long long ans=check(n,m);
	long long p=ans;
	for(int i=1;i<=k;i++){
		int num=m,sum=n;
		sum++;
		for(int j=1;j<=n;j++)g[++num]={sum,j,a[i][j]};
		long long mm=c[i]+check(sum,num);
		ans=min(ans,mm);
		if(mm>=p||pos==1)vis[i]=1;
		pos=0;
	}
	for(int s=1;s<(1<<k);s++){
		long long cnt=0;
		int sum=n,num=m,b=1;
		for(int i=1;i<=k;i++){
			if(vis[i]&&s&(1<<(i-1))){
				b=0;
				break;
			}
		}
		for(int i=1;i<=k&&b;i++){
			if(s&(1<<(i-1))){
				if((s^(1<<(i-1)))==0){
					b=0;
					break;
				}
				cnt+=c[i];
				sum++;
				for(int j=1;j<=n;j++){
					g[++num]={sum,j,a[i][j]};
				}
			}
		}
		if(b)ans=min(ans,cnt+check(sum,num));
	}
	cout<<ans;
	return 0;
}

