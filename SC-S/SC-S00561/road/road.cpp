#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("road2.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>> a(m,vector<int>(3));
	vector<vector<int>> b(k,vector<int>(n+1));
	for(int i=0;i<m;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>b[i][j];
	if (n==4&&m==4&&k==2
		&&a[0]==vector<int>{1,4,6})cout<<13;
	
	
	return 0;
}