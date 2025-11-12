#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt=0,sum=0,ans=0,fa[10005];
long long find(int x){return fa[x]=(fa[x]==x?x:find(fa[x]));}
struct d{
	long long u;
	long long v;
	long long w;
}h[1000006];
bool cmp(d x,d y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		h[++cnt].u=x,h[cnt].v=y,h[cnt].w=z;
	}
	sort(h+1,h+cnt+1,cmp);
	for(int i=1;i<=m;i++){
		int fata=find(h[i].u),fatb=find(h[i].v);
		if(fata!=fatb) sum++,ans+=h[i].w,fa[h[i].u]=h[i].v;
		if(sum==n-1) break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
