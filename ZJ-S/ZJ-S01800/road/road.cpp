#include <bits/stdc++.h>
#define int long long
#define rint register int
#define PII pair<int,int>
#define P pair<int,PII>
#define fir first
#define sec second
using namespace std;
const int N=10020;
int n,m,k;
int vtoc[15];
vector <P> q;
int fa[N];
int find(rint x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	rint u,v,w;
	while(m--){
		cin>>u>>v>>w;
		q.push_back({w,{u,v}});
	}
	for(rint i=1;i<=k;i++){
		rint a[N];
		cin>>vtoc[i];
		for(rint j=1;j<=n;j++)cin>>a[j];
		rint x=0;
		for(rint j=1;j<=n;j++)if(a[j]==0){
			x=j;
			break;
		}
		for(rint j=1;j<=n;j++)
			if(x!=j)q.push_back({a[j],{x,j}});
	}
	sort(q.begin(),q.end());
	for(rint i=1;i<=n;i++)fa[i]=i;
	rint ans=0;
	for(rint i=0;i<q.size();i++){
		rint l=q[i].fir;
		rint s=q[i].sec.fir;
		rint t=q[i].sec.sec;
		rint x=find(s),y=find(t);
		if(x==y)continue;
		else{
			ans+=l;
			fa[x]=y;
		}
	}
	cout<<ans;
	return 0;
}
