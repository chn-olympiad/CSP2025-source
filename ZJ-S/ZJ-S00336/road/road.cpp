#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,k,ans,f[11111],a[111111][21],s1,a1=LLONG_MAX,rt[111];
struct er{
	int u,v,w;
}e[11111111];
bool cmp(er x,er y){
	return x.w<y.w;
}
int fi(int x){
	return f[x]==x?x:f[x]=fi(f[x]);
}
void pr(){
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(fi(e[i].u)!=fi(e[i].v))f[fi(e[i].u)]=fi(e[i].v),ans+=e[i].w;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n*10;i++)f[i]=i;
	for(int i=1,u,v,w;i<=m;i++)cnt++,cin>>e[cnt].u>>e[cnt].v>>e[cnt].w,cnt++,e[cnt]={e[cnt-1].v,e[cnt-1].u,e[cnt-1].w};
	for(int i=1,x,y;i<=k;i++){
		cin>>rt[i];
		e[++cnt]={0,n+i,rt[i]};
		e[++cnt]={n+i,0,rt[i]};
		for(int i1=1;i1<=n;i1++)cin>>a[i][i1];
	}
	s1=cnt;
	for(int i=0;i<(1<<k);i++){
		ans=0;
		cnt=s1;
		for(int i1=0;i1<=n*2;i1++)f[i1]=i1;
		for(int i1=0;i1<k;i1++){
			if(((1<<i1)&i)){
				for(int i11=1;i11<=n;i11++)e[++cnt]={n+i1+1,i11,a[i1+1][i11]},e[++cnt]={i11,n+i1+1,a[i1+1][i11]};
				ans+=rt[i1];
			}
		}
		pr();
		a1=min(a1,ans);
	}
	cout<<a1;
	return 0;
}
