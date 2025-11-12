#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=3e4+100,M=2e6+100100;
int n,m,k,uu[M],vv[M],fr[N],to[N],id[N],s[N],c[N],cnt;
pii a[M],b[N];
ll ans,res;
void init(){
	for(int i=1;i<N;i++)s[i]=i;
}
int find(int x){
	return x==s[x]?x:s[x]=find(s[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	s[x]=y;
}
void low1(){
	int u,v,nu,nv;
	init();
	for(int i=1;i<=m;i++){
		u=uu[a[i].second],v=vv[a[i].second];
		nu=find(u),nv=find(v);
		if(nu==nv)continue;
		merge(nu,nv);
		ans+=a[i].first;
		cnt++;
		fr[cnt]=u,to[cnt]=v;
		id[cnt]=i;
		if(cnt==n-1)return;
	}
}
void low2(){
	int u,v,nu,nv;
	for(int p=1;p<(1<<k);p++){
		res=0;
		for(int i=1;i<=n-1;i++){
			b[i]=(pii){a[id[i]].first,a[id[i]].second};
		}
		int q=p;
		cnt=n-1;
		for(int i=0;i<k;i++){
			if(q&1){
				for(int j=m+1+i*n;j<=m+i*n+n;j++){
					b[++cnt]=a[j];
				}
			}
			q/=2;
		}
		sort(b+1,b+cnt+1);
		init();
		for(int i=1;i<=cnt;i++){
			u=uu[b[i].second],v=vv[b[i].second];
			nu=find(u),nv=find(v);
			if(nu==nv)continue;
			merge(nu,nv);
			res+=b[i].first;
		}
		q=p;
		for(int i=0;i<k;i++){
			if(q&1){
				res+=c[i+1];
			}
			q/=2;
		}
		ans=min(ans,res);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&uu[i],&vv[i],&a[i].first);
		a[i].second=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			uu[m+(i-1)*n+j]=n+i,vv[m+(i-1)*n+j]=j;
			scanf("%d",&a[m+(i-1)*n+j].first);
			a[m+(i-1)*n+j].second=m+(i-1)*n+j;
		}
	}
	sort(a+1,a+m+1);
	low1();
	if(k==0){
		printf("%lld\n",ans);
		return 0;
	}
	low2();
	printf("%lld\n",ans);
	return 0; 
}