#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int j,sum,f[N],fx,fy,b,s1;
int n,m,k,i,w[N],t,sum1,qrqr;
int bb[N];
struct Node{int u,v,w;}c[N];
bool cmp(Node a,Node b){return a.w<b.w;}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n+1;i++)f[i]=i,bb[i]=2e9;
	for(i=1;i<=m;i++)cin>>c[i].u>>c[i].v>>c[i].w;
	for(i=1;i<=k;i++){
	  cin>>w[i];
	  for(j=1;j<=n;j++)cin>>b,bb[j]=min(bb[j],b);
	}
	for(i=1;i<=n;i++)c[i+m].u=i,c[i+m].v=n+1,c[i+m].w=bb[i];
	sort(c+1,c+(1+m+n),cmp);
	for(i=1;i<=m+n+1;i++)
	  if(c[i].v<=n&&c[i].u<=n){
		fx=find(c[i].u);
		fy=find(c[i].v);
		if(fx!=fy)f[fx]=fy,sum+=c[i].w;
	  }
	for(i=1;i<=n;i++)if(f[i]==i)qrqr++;
	if(qrqr>1)sum=2e12;
	for(i=1;i<=n+1;i++)f[i]=i;
	sum1=0;
	for(i=1;i<=m+n+1;i++){
		fx=find(c[i].u);
		fy=find(c[i].v);
		if(fx!=fy)f[fx]=fy,sum1+=c[i].w;
	}
	cout<<min(sum,sum1);
	return 0;
	
	

}
