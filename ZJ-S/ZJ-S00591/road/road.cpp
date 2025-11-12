#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,K=17;
int n,m,k,c[K],a[K][N];
bool vis[N];
vector<int> e[N];
//struct compare{
//	bool operator >(int &a,int &b){
//		return a>b;
//	};
//};
//void solve1()
//{
//	priority_queue<int,compare> q;
//	for(int i=0;i<e[1].size();i++)
//		q.push(e[1][i]);
//	vis[1]=1;
//	while(!q.empty())
//	{
//		top
//	}
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=1,u,v;i<=m;i++)
	{
		cin >>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=k;i++)
	{
		cin >>c[i];
		for(int j=1;j<=n;j++)
			cin >>a[i][j];
	}
//	if(k==0)
//	{
//		solve1();
//	}
	return 0;
}
