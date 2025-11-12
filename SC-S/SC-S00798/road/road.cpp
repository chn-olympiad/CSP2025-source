#include<bits/stdc++.h>
using namespace std;
struct type{
	long long u,v,w;
};
bool cmp(type x,type y){
	if(x.w<=y.w){
		return true;
	}
	return false;
}
long long n,m,k,c[15][1010],f[1010],e[15],book[1010];
long long num,ans=0;
type a[1000010];
void gg(int x,int y){
	if(f[x]!=x){
		gg(f[x],y);
	} 
	f[x]=y;
}
int find(int x){
	if(f[x]==x){
		return x;
	}else{
		return find(f[x]);
	}
}
void make(int x,int y){
	if(f[x]>f[y]){
		gg(x,f[y]);
	}else{
		gg(y,f[x]);
	}
}
void dfs(int l){
	if(l>k)return;
	e[l]=1;
	num+=c[l][0];
	int o=n-1;
	for(int i=1;i<=n;i++){
		book[i]=1;
	}
	for(int i=1;i<=m;i++){
		if(o==0){
			break;
		}
		if(find(a[i].v)!=find(a[i].u)){
			make(a[i].v,a[i].u);
			book[a[i].u]=0;
			book[a[i].v]=0;
			long long mu=1e18;
			for(int j=1;j<=k;j++){
				if(e[j]==0)continue;
				mu=min(mu,c[j][a[i].u]+c[j][a[i].v]);
			}
			num+=min(a[i].w,mu);
			o--;
		}
	}
	if(o>0){
		for(int i=1;i<=n;i++){
			if(book[i]==0)continue;
			long long mu=1e18;
			for(int j=1;j<=k;j++){
				if(e[j]==0)continue;
				for(int r=1;r<=n;r++){
					if(book[r]==0){
						mu=min(mu,c[j][r]+c[j][i]);
					}
				} 
			}
			num+=mu;
			o--;
			if(o==0){
				break;
			}
		}
	}
	ans=min(ans,num);
	dfs(l+1);
	e[l]=0;
	dfs(l+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int o=n-1;
	for(int i=1;i<=m;i++){
		if(o==0){
			break;
		}
		if(f[a[i].v]!=f[a[i].u]){
			if(f[a[i].v]<f[a[i].u]){
				f[a[i].u]=f[a[i].v];
			}else{
				f[a[i].v]=f[a[i].u];
			}
			ans+=a[i].w;
			o--;
		}
	}
	if(o>0){
		ans=1e18;
	}
	dfs(1); 
	printf("%lld",ans);
	return 0;
} 