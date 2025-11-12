#include<bits/stdc++.h>
using namespace std;
int T,n,a[100001][4],ans;
vector<int> b[4];
bool cmp1(int i,int j)
{
	return (min(a[i][1] - a[i][2],a[i][1] - a[i][3]) > min(a[j][1] - a[j][2],a[j][1] - a[j][3]));
}

bool cmp2(int i,int j)
{
	return (min(a[i][2] - a[i][1],a[i][2] - a[i][3]) > min(a[j][2] - a[j][1],a[j][2] - a[j][3]));
}

bool cmp3(int i,int j)
{
	return (min(a[i][3] - a[i][1],a[i][3] - a[i][2]) > min(a[j][3] - a[j][1],a[j][3] - a[j][2]));
}
void go_work()
{
	ans = 0,b[1].clear(),b[2].clear(),b[3].clear();
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 3;j++) cin >> a[i][j];
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) b[1].push_back(i);
		else if(a[i][2] >= a[i][3] && a[i][2] >= a[i][1]) b[2].push_back(i);
		else b[3].push_back(i);
	}
	if(b[1].size() > n / 2)
	{
		sort(b[1].begin(),b[1].end(),cmp1);
		while(b[1].size() > n / 2)
		{
			int t = b[1].back();
			if(a[t][1] - a[t][2] <= a[t][1] - a[t][3]) b[2].push_back(t);
			else b[3].push_back(t);
			b[1].pop_back();
		}
	}
	if(b[2].size() > n / 2)
	{
		sort(b[2].begin(),b[2].end(),cmp2);
		while(b[2].size() > n / 2)
		{
			int t = b[2].back();
			if(a[t][2] - a[t][1] <= a[t][2] - a[t][3] && b[1].size() != n / 2) b[1].push_back(t);
			else b[3].push_back(t);
			b[2].pop_back();
		}
	}
	if(b[3].size() > n / 2)
	{
		sort(b[3].begin(),b[3].end(),cmp3);
		while(b[3].size() > n / 2)
		{
			int t = b[3].back();
			if(a[t][3] - a[t][1] <= a[t][3] - a[t][2] && b[1].size() != n / 2) b[1].push_back(t);
			else if(b[2].size() != n / 2) b[2].push_back(t);
			b[3].pop_back();
		}
	}
	for(int i = 1;i <= 3;i++) for(auto x : b[i]) ans += a[x][i];
	cout << ans << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--) go_work();
	return 0;
}
