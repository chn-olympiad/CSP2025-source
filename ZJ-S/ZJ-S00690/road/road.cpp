#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1159764;

int n,m,k;
int c[20],a[20][10086];
ll ans;
int fa[10086];
int find(int x){
 return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edges{
 int u,v,w;
}e[nmax],ee[nmax];
int cmp(edges a,edges b){
 return a.w<b.w;
}
int main() {
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
 ios::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 
 //cout<<(21*1e6*log2(1e6));return 0;
 
 cin>>n>>m>>k;

 for(int i=1;i <=m;i ++){
  cin >>e[i].u>>e[i].v>>e[i].w;
  //cost[{min(u,v),max(u,v)}]=w;
 }
 for(int i = 1;i <=k;i ++){
  cin>>c[i];
  for(int j =1;j<=n;j++)
   {
   	cin>>a[i][j];
   	//e[j].u=n+i,e[j].v=n+j-n*i;
   	//e[j].w=a[i][n+j-n*i];
   }
 }
 ll ans=1e18;
 for(int _=0;_<(1<<k);_++){
  ll cnt=0;int top=m;int cnt_c=0;
  for(int i=1;i<=m;i++)ee[i]=e[i];
  for(int i=0;i<k;i++){
  	if((_>>i) & 1){
	 cnt+=c[i+1];cnt_c++;
	 for(int ii=top+1;ii<=top+n;ii++){
	 	ee[ii].u=n+i+1;
	 	ee[ii].v=ii-top;
	 	ee[ii].w=a[i+1][ii-top];
	 }
	 top+=n;
	}
  }
  for(int i=1;i<=n+k;i++){
   fa[i]=i;
  }
  sort(ee+1,ee+1+top,cmp);
  ll cnt2=0;
  for(int i = 1;i <= top;i ++){
   int u = ee[i].u,v=ee[i].v;
   int w=ee[i].w;
   if(find(u)==find(v))continue;
   
   cnt2++;
   fa[find(u)]=find(v);
   cnt+=w;
   if(cnt2==n+cnt_c-1)break;
  }
  ans=min(ans,cnt);
 }
 cout<<ans;
 return 0;
}