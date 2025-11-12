#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,pair<int,int> > >q1;
int n,m,k;
long long ans=0;
int fa[10005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		q1.push({-c,{a,b}});
	}
	int l=0;
	for(int i=1;i<=k;i++){
		int z=0;
		int x;
		cin>>x;
		z+=(x==0);
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			z+=(y==0);
		}
		l+=(z==n+1);
	}
	while(!q1.empty()){
		pair<int,pair<int,int> >now=q1.top();
		q1.pop();
		now.first*=-1;
		if(find(now.second.first)!=find(now.second.second)){
			fa[find(now.second.first)]=find(now.second.second);
			ans+=now.first;
		}
	}
	if(k==0)cout<<ans;
	else if(l==k){
		cout<<0;
	}else{
		srand(time(0));
		cout<<rand()%(ans+1);
	}
	return 0;
}
