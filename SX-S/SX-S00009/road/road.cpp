#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ok,ans;
struct P{
	int u,v,w;
}e[2000006],e1[1000006];
int c[15];
int a[15][10005],ff[10005];
bool cmp(P x,P y){
	return x.w<y.w;
}
int find(int h){
	if(h==ff[h])return h;
	return ff[h]=find(ff[h]);
}
int hh=0,rty[25],cnt;
int kkk(){
	int sum=0;
	ok=0;
	for(int i=1;i<=n;i++)ff[i]=i;
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int u=e[i].u;
		int v=e[i].v;
		int uu=find(u);
		int vv=find(v);
		if(uu==vv)continue;
		ff[uu]=vv;
		sum+=e[i].w;
		ok++;
		if(ok==n-1)break;
	}
	return sum;
}
void dfs(int u,int sum,int kk){
	if(sum+k-u+1<kk)return ;
	if(sum>kk){
		cnt=m;
		for(int i=1;i<=m;i++)e1[i]=e[i];
		int lll=0;
	//	cout<<"rty"<<kk<<' '<<hh<<endl;
		for(int i=1;i<=sum-1;i++){
			lll+=c[rty[i]];
		//	cout<<rty[i]<<' ';
			for(int j=1;j<=n-1;j++){
				for(int l=j+1;l<=n;l++){
					cnt++;
					e[cnt].u=j;
					e[cnt].v=l;
					e[cnt].w=a[rty[i]][j]+a[rty[i]][l];
				}
			}
		}
		lll+=kkk();
	//	cout<<sum-1<<' '<<lll<<endl;
		ans=min(ans,lll);
		for(int i=1;i<=m;i++)e[i]=e1[i];
		return ;
	}
	if(u>k)return ;
	rty[sum]=u;
	dfs(u+1,sum+1,kk);
	dfs(u+1,sum,kk);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0){
		ok=0;
		for(int i=1;i<=n;i++)ff[i]=i;
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			int u=e[i].u;
			int v=e[i].v;
			int uu=find(u);
			int vv=find(v);
			if(uu==vv)continue;
			ff[uu]=vv;
			ans+=e[i].w;
			ok++;
			if(ok==n-1)break;
		}
		printf("%lld",ans);
		return 0;
	}
	ok=0;
	for(int i=1;i<=n;i++)ff[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		int uu=find(u);
		int vv=find(v);
		if(uu==vv)continue;
		ff[uu]=vv;
		ans+=e[i].w;
		ok++;
		if(ok==n-1)break;
	}
	for(int i=1;i<=k;i++){
		cnt=m;
		dfs(1,1,i);
	}
	cout<<ans;
	return 0;
}