#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,sum;
struct ed{
	int u,v;
	ll w;
};
ed e[2000005],e2[500005],e3[50005];
ed vill[15][11005];
int f[110005],cnt,c[105];
int cmp1(ed r,ed l){
	return r.w<l.w;
}
int Find(int x){
	if(x!=f[x])return f[x]=Find(f[x]);
	else return x;
}
void Union(int jlx,int jly){
	jlx=Find(jlx),jly=Find(jly);
	f[jlx]=jly;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&vill[i][j].w);
			vill[i][j].u=j;
			vill[i][j].v=n+i;
		}
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(e+1,e+m+1,cmp1);
	int jl=0;
	for(int i=1;i<=m;i++){
		int fu=Find(e[i].u),fv=Find(e[i].v);
		if(fu!=fv){
			jl++;
			Union(fu,fv);
			sum+=e[i].w;
			e3[jl].u=e[i].u,e3[jl].v=e[i].v,e3[jl].w=e[i].w;
		}
		if(jl==n-1)break;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	ans=sum;
	sum=0;
	int bian=n-1,dian=n;
	int zongshu=0;
	for(int i=1;i<=k;i++){
		zongshu=zongshu*2+1;
	}
	for(int i=0;i<=zongshu;i++){
		for(int j=1;j<=n;j++)
			e2[j]=e3[j];
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
//				cout<<j<<' '<<(1<<(j-1))<<' '<<i&&(1<<(j-1));
				sum+=c[j];
				f[n+j]=n+j;
				dian++;
				for(int k=1;k<=n;k++)
					e2[bian+k]=vill[j][k];
				bian+=n; 
			}
		}
		sort(e2+1,e2+bian+1,cmp1);
		for(int j=1;j<=bian;j++){
			int fu=Find(e2[j].u),fv=Find(e2[j].v);
			if(fu!=fv){
				jl++;
				Union(fu,fv);
				sum+=e2[j].w;
			}
			if(jl==dian-1)break;
		}
		ans=min(ans,sum);
		for(int j=1;j<=n;j++)
			f[j]=j;
		for(int j=n+1;j<=n+15;j++)f[j]=0;
		for(int j=1;j<=bian;j++)
		{
			e2[j].u=0;
			e2[j].v=0;
			e2[j].w=0;
		}
		bian=n-1;
		dian=n;
//		cout<<i<<' '<<sum<<"\n";
		sum=0;
	}
	printf("%lld\n",ans);
	return 0;
}
