/*
wei shen me road4 de 'm' zhi you 1e5?
da shu ju shi xiao shu ju
jiu lian da shu ju ye yao xia du ma , ha ji chu ti ren , ni zhe jia huo
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int n,m,k,c[15],v[15],sum[15],f[400005];
struct node{
	int x,y,w;
}e[4000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void Onion(int x,int y){
	f[find(x)]=find(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld %lld %lld",&e[i].x,&e[i].y,&e[i].w);
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+m+k*n+1,cmp);
		for(int i=1;i<=m;i++){
			int x=e[i].x,y=e[i].y,w=e[i].w;
			if(find(x)==find(y)) continue;
			Onion(x,y);ans+=w;
		}
		printf("%lld\n",ans);
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) cnt++;
		for(int j=1;j<=n;j++){
			scanf("%lld",&e[m+(i-1)*n+j].w);
			e[m+(i-1)*n+j].x=i+n,e[m+(i-1)*n+j].y=j;
		}
	}
	sort(e+1,e+m+k*n+1,cmp);
	if(cnt==k){
		int ans=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=m+k*n;i++){
			int x=e[i].x,y=e[i].y,w=e[i].w;
			if(find(x)==find(y)) continue;
			Onion(x,y);ans+=w;
			if(x>n) v[x-n]++,sum[x-n]+=w;
			if(y>n) v[y-n]++,sum[y-n]+=w;
		}
		for(int i=1;i<=k;i++) if(v[i]==1) ans-=sum[i];
		printf("%lld\n",ans);
	}else{
		int mn=1e18;
		for(int i=0;i<(1<<k);i++){
			int ans=0;
			for(int j=1;j<=k;j++){
				if(i&(1ll<<(j-1))) ans+=c[j];
				sum[j]=0;v[j]=0;
			}
			for(int j=1;j<=n+k;j++) f[j]=j;
			for(int j=1;j<=m+k*n;j++){
				int x=e[j].x,y=e[j].y,w=e[j].w;
				if(find(x)==find(y)||(x>n&&!(i&(1ll<<(x-n-1))))||(y>n&&!(i&(1ll<<(y-n-1))))) continue;
				Onion(x,y);ans+=w;
				if(x>n) v[x-n]++,sum[x-n]+=w;
				if(y>n) v[y-n]++,sum[y-n]+=w;
			}
			for(int j=1;j<=k;j++) if(v[j]==1) ans-=sum[j];
			mn=min(mn,ans);
		}
		cout<<mn<<endl;
	}
	return 0;
}
