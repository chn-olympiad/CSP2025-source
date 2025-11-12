#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct road{
	int data;
	int v;
};
struct trueroad{
	int data;
	int u,v;
};
int cmp(road a,road b){
	return a.data<b.data;
}
int trueroad_cmp(trueroad a,trueroad b){
	return a.data<b.data;
}
trueroad s[M];	
vector<road>a[N],copya[N],b[N];int n,m,k;
int fa[M];
void findfatherfirststep(){
	for(int i=0;i<m;i++){
		fa[m]=m;
	}
}

int findfather(int m){
	if(fa[m]==m){
		return m;
	}
	return fa[m]=findfather(m);
}
int ans=INT_MAX;
void dfs(int c,int wei){
	if(c>k){
		int l=0;
		for(int i=1;i<=n;i++){
			for(road j:a[i]){
				s[l].data=j.data;s[l].u=i;s[l].v=j.v;
				l++;
			}
		}
		sort(s,s+l,trueroad_cmp);
		findfatherfirststep();
		int cnt=0;
		for(int i=0;i<l;i++){
			if(findfather(s[i].u)!=findfather(s[i].v)){
				cnt+=s[i].data;
			}
		}
		cnt+=wei;
		ans=min(ans,cnt);
		return;
	}
	dfs(c+1,wei);
	for(int i=1;i<=n;i++){
		copya[i].clear();
	}
	
	for(int i=1;i<=n;i++){
		for(road j:a[i]){
			copya[i].push_back(j);
		}
	}
	int flag=1;
	for(road j:b[c]){
		if(!flag){
			flag=0;
			for(road q:a[c]){
				if(q.v==j.v){
					flag=1;
					q.data=max(q.data,j.data);
				} 
			}
			if(!flag){
				a[c].push_back(j);a[j.v].push_back({j.data,c});
			}
			
		}flag=0;
		
	}
	dfs(c+1,wei+b[c][0].data);
	for(int i=1;i<=n;i++){
		a[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(road j:copya[i]){
			a[i].push_back(j);
		}
	}
} 
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		a[u].push_back({w,v});a[v].push_back({w,u});
	}

	for(int i=1;i<=k;i++){
		cin>>w;
		b[i].push_back({w,0});
		for(int j=1;j<=n;j++){
			cin>>w;
			b[i].push_back({w,j});
		}
		
	}
	
	dfs(1,0);
	cout<<ans;
	return 0;
}