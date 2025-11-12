#include <bits/stdc++.h> 
using namespace std;
int fa[10005];
int Find(int x)
{
	if(fa[x] == x)return x;
	else{
		return fa[x] = Find(fa[x]);
	}
}
vector<array<int,3>> edge;
bool cmp(array<int,3> a,array<int,3> b)
{
	return a[2] < b[2];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u,v,w; 
	for(int i = 0;i < m;i++)
	{
		if(i <= n)fa[i] = i;
		cin >> u >> v >> w;
		edge.push_back({u,v,w});
	}
	bool flaga = 1;
	for(int i = 1;i <= k;i++)
	{
		cin >> w;
		for(int j = 1;j <= n;j++)
		{
			cin >> u;
			edge.push_back({i,j,u});
			if(u != 0 || w != 0)flaga = 0;
		}
	}
	long long sum = 0;
	
	if(flaga || k == 0){
		int i = 0;
		int cnt = 0;
		sort(edge.begin(),edge.end(),cmp);
		for(auto i : edge)
		{
			if(Find(i[0]) != Find(i[1]))
			{
				cnt++;
				sum += i[2];
				fa[Find(i[0])] = Find(i[1]);
			}
			if(cnt == n+k)break;
		}
		cout << sum << endl;
	}
}
