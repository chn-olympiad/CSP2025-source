#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,w,ans,done[10005],dm=0,idx=0;
struct node{
	int a,b;
}p[10005];

priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		q.push({w,++idx});
		p[idx]={u,v};
	}
//	done[p[q.top().second].a]=1;
//	done[p[q.top().second].b]=1;
	for(int i=1;i<=n-1;i++){
		ans+=q.top().first;
		q.pop();
	}
	printf("%d",ans);
	
	return 0;
}