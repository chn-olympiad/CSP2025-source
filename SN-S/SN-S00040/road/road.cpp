//SN-S00040
#include<bits/stdc++.h>
using namespace std;
const long long fyc=2e6+5,imc=1e4+50;
struct node{
	long long u,v,w;
}s[fyc];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long n,m,k,a[15][imc],c[15],fa[imc],sum,ans=2147483647,cnt,t[15],n1,m1;
long long f(long long x){
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++) cin>>s[i].u>>s[i].v>>s[i].w;
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++) cin>>a[i][j];
	}
	for(long long i=0;i<(1<<k);i++){
		sum=cnt=0,n1=n,m1=m;
		for(long long j=i;j;j/=2) t[++cnt]=j%2;
		for(long long j=1;j<=k;j++){
			if(t[j]==1){
				n1++,sum+=c[j];
				for(long long l=1;l<=n;l++) s[++m1].u=n1,s[m1].v=l,s[m1].w=a[j][l];
			}
		}
		cnt=0;
		for(long long j=1;j<=n1;j++) fa[j]=j;
		sort(s+1,s+m1+1,cmp);
		for(long long j=1;j<=m1;j++){
			long long x=f(s[j].u),y=f(s[j].v);
			if(x==y) continue;
			else{
				fa[x]=y;
				sum+=s[j].w;
				cnt++;
			}
			if(cnt==n1-1) break;
		}
		if(cnt==n1-1) ans=min(ans,sum);
	}
	cout<<ans;
}
