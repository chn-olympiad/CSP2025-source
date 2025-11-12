#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+100,M=1e6+10;
int n,m,k;
int f[N];
int c[20],cnt;
ll p=-1;
int s=1;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
struct node{
	int u,v,w;
}a[2*M],b[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])s=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&b[++cnt].w);
			b[cnt].u=i+n,b[cnt].v=j;
		}
	}
	if(s==1){
		for(int i=1;i<=k;i++){
			int st=i*(n-1)+1,ed=i*n,u;
			for(int j=st;j<=ed;j++){
				if(b[j].w==0){
					u=b[j].v;
					break;
				}
			}for(int j=st;j<=ed;j++){
				if(b[j].v==u)continue;
				a[++m]={u,b[j].v,b[j].w};
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	if(k==0||s==1){
		ll sum=0,ans=0;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			if(find(a[i].u)!=find(a[i].v)){
				f[find(a[i].u)]=find(a[i].v);
				sum++;
				ans+=a[i].w;
			}
		}cout<<ans;
		return 0;
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=(1<<k)-1;i;i--){
		ll sum=0,ans=0,k1=1,k2=1,t[20]={};
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				sum++;
				ans+=c[j];
				t[j]=1;
			}else t[j]=0;
		}for(int j=1;j<=n+k-1;j++)f[j]=j;
		for(int j=1;j<=n+sum-1;j++){
			while((!t[b[k2].u-n]||find(b[k2].u)==find(b[k2].v))&&(k2<=cnt))k2++;
			while(find(a[k1].u)==find(a[k1].v)&&k1<=m)k1++;
			if(k2>cnt||a[k1].w<b[k2].w){
				ans+=a[k1].w;
				f[find(a[k1].u)]=find(a[k1].v);
				k1++;
			}else {
				ans+=b[k2].w;
				f[find(b[k2].u)]=find(b[k2].v);
				k2++;
			}
		}if(p==-1)p=ans;
		else p=min(p,ans);
	}cout<<p;
	return 0;
}
