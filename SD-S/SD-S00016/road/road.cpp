#include<bits/stdc++.h>
#define pii pair<long long,long long> 
#define ll long long
using namespace std;
const int N = 1e5 + 9;
int n,m,k,w[N],dis[N],p[N],c[N],sum;
vector<pii> v[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n + k;i++) dis[i] = 1e9;
	dis[1] = 0;
	for(int i = 1;i <= m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> w[i + n];
		for(int j = 1;j <= n;j++)
		{
			int x;
			cin >> x;
			v[i + n].push_back({j,x});
			v[j].push_back({i + n,x});
		}
	}
	q.push({0,1});
	int cnt = 0;
	while(!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if(p[x]) continue;
		for(int i = 0;i < v[x].size();i++)
		{
			int z = v[x][i].second;
			int y = v[x][i].first;
			if(y > n && !c[y])
			{
				z += w[i];
				c[y] = 1;
			} 
			if(dis[y] > dis[x] + z)
			{
				p[x] = 1;
//				cout << y << endl;
				sum += z;
				dis[y] = dis[x] + z;
				
				q.push({dis[y], y});
				if(y <= n) cnt++;
			}
		}
		if(cnt == n - 1) break;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
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

13
*/
