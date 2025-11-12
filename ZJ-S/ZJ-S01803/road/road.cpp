#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,p,t;
ll ans,c[20];
int f[10020];
struct st{
	int u,v,r;
	ll w;
}a[1010010];
bool cmp(st a,st b){
	return a.w<b.w;
}
int find(int a){
	if(f[a]==a)return a;
	return f[a]=find(f[a]);
}
ll zg(){
	ll cnt=0;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=n+k;i++)f[i]=i;
	int yj=1;
	for(int i=1;i<=t;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y)continue;
		f[x]=y;
		yj++;
		cnt+=a[i].w;
		if(yj==n+k)break;
	}
	return cnt;
}
int g[15],k1;
ll dfs(int x){
	if(x>k){
		ll cnt=0;
		for(int i=1;i<=n+k;i++)f[i]=i;
		int yj=1;
		for(int i=1;i<=t;i++){
			int x=find(a[i].u),y=find(a[i].v);
			if(x==y)continue;
			if(a[i].v>n && !g[a[i].v-n])continue;
			f[x]=y;
			yj++;
			cnt+=a[i].w;
			if(yj==n+k1)break;
		}
		for(int i=1;i<=k;i++)cnt+=g[i]*c[i];
		return cnt;
	}
	ll c1=dfs(x+1);
	g[x]=1;
	k1++;
	ll c2=dfs(x+1);
	g[x]=0;
	k1--;
	return min(c1,c2);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	t=m;
	int flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])flag=0;
		int flag2=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&p);
			a[++t].u=j;
			a[t].v=n+i;
			a[t].w=p;
			if(p==0)flag2=0;
		}
		if(flag2)flag=0;
	}
	if(k==0 || flag==1)cout<<zg();
	else{
		sort(a+1,a+t+1,cmp);
		cout<<dfs(1);
	}
	return 0;
}
