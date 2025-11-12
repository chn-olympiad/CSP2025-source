#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4+4,maxm=1e6+4,maxk=14;
ll n,m,k,c[maxk],b[maxk][maxn+1],fa[maxn+maxk];
bool f[maxk];
struct zzz{
	ll u,v,w;
}a[maxm];
bool cmp(zzz x,zzz y){
	if(x.u==y.u&&x.w==y.w)
	  return x.v<y.v;
	else if(x.w==y.w)
	  return x.u<y.u;
	else
	  return x.w<y.w;
}
int getfa(int g){
	if(fa[g]==g)
	  return g;
	return fa[g]=getfa(fa[g]);
}
void krus1(){
	int ans=0,sum=0;
	for(int i=1;i<=m;i++){
	  if(sum==n-1)
	    break;
	  int fx=getfa(a[i].u),fy=getfa(a[i].v);
	  if(fx==fy)
	    continue;
	  fa[fy]=fx;
	  sum++;
	  ans+=a[i].w;
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	  cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
	  cin>>c[i];
	  for(int j=1;j<=n;j++)
	    cin>>b[i][j],b[i][n+1]+=b[i][j];
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n+k;i++)
	  fa[i]=i;
	if(1){
	  krus1();
	  return 0;
	}
	return 0;
}
