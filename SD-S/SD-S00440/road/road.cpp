#include<cmath>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10015;
long long fa[N],n,m,k,vi[N],tot[N],c[N],ans=1e13;
struct node{
	long long to,val;
};
bool operator <(node i,node j){
	if(i.val>j.val)return 1;
	return 0;
} 
priority_queue<node>q;
vector<node>s[N];
int find(int i){
	if(fa[i]==i)return i;
	return fa[i]=find(fa[i]);
}
void merge(int i,int j){
	fa[find(i)]=find(j);
}
bool cmp(node i,node j){
	if(i.val<j.val)return 1;
	return 0;
}
void dfs(int now,long long mone){
	long long nom=mone,num=0,t=0;
	//cout<<endl<<endl<<now<<endl;
	while(!q.empty())
		q.pop();
	for(int i=1;i<=n+now;i++){
		tot[i]=0;
		if(c[i]==0)continue;
		t++;
		fa[i]=i;
		q.push({i,s[i][0].val});
	}
	while(!q.empty()&&num<t-1){
		int u=q.top().to;
		q.pop();
		int v=s[u][tot[u]].to;
		tot[u]++;
		if(find(v)==find(u)||c[v]==0){
			if(tot[u]<s[u].size())
				q.push({u,s[u][tot[u]].val});
			continue;
		}
	//	cout<<u<<" "<<v<<endl;
		if(find(v)!=find(u)&&c[v]==1){
			merge(v,u);num++;
			nom+=s[u][tot[u]-1].val;
		}
	}
	ans=min(ans,nom);
	if(now>=k)return;
	c[now+n+1]=1;
	dfs(now+1,mone+vi[now+1]);
	c[now+n+1]=0;
	dfs(now+1,mone);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		s[x].push_back({y,w});
		s[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++){
		cin>>vi[i];
		for(int j=1;j<=n;j++){ 
			cin>>y;
			s[j].push_back({i+n,y});
			s[i+n].push_back({j,y});
		}
	}
	for(int i=1;i<=n;i++)c[i]=1;
	for(int i=1;i<=n+k;i++)
		stable_sort(s[i].begin(),s[i].end(),cmp);
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

3 2 1
1 2 2
1 3 100
1 3 1000 2
*/
