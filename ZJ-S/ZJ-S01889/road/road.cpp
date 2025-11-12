#include<bits/stdc++.h>
using namespace std;
const int MS=1e4+5;
int n,m,k,c[15],a[15][MS],opt[15];
long long ans=1e18;
struct node{
	int w,u,v;
};
int f[MS];
int findfa(int a){
	if(f[a]==a)return a;
	return f[a]=findfa(f[a]);
}
vector<node> e,ne,xe[15];//first=w second=u
priority_queue<pair<int,int>> pq;//first=w second=u
bool cmp(node a,node b){
	return a.w<b.w;
}
bool flag=1;
long long solve(int key){
	ne=e;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<k;i++)
		if(key&(1<<i)){
			for(int j=0;j<xe[i].size();j++)
				ne.push_back(xe[i][j]);
		}
	sort(ne.begin(),ne.end(),cmp);
	int cnt=0;
	long long res=0;
	for(int i=0;i<ne.size();i++){
		if(findfa(ne[i].v)!=findfa(ne[i].u)){
			cnt++;
			res+=ne[i].w;
			f[findfa(ne[i].v)]=findfa(ne[i].u);
		}
		if(cnt==n-1)break;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		node t;
		t.v=v; t.w=w; t.u=u;
		e.push_back(t);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)flag=0;
		opt[i]=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][opt[i]]>a[i][j])opt[i]=j;
		}
		if(a[i][opt[i]]!=0)flag=0;
		for(int j=1;j<=n;j++){
			if(j==opt[i])continue;
			node t;
			t.u=opt[i]; t.v=j;
			t.w=a[i][j];
			xe[i].push_back(t);
		}
	}
	if(flag){
		ans=solve((1<<k)-1);
	}else
	for(int i=0;i<(1<<k);i++){
		long long tem=0;
		tem=solve(i);
		for(int j=0;j<k;j++)
			if(i&(1<<j))tem+=c[j]+a[j][opt[j]];
		ans=min(ans,tem);
	}
	printf("%lld\n",ans);
	return 0;
}
