#include<bits/stdc++.h>
#define endl '\n'
#define elif else if
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	int output = 0;
	for(int i = 0;i < m;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < m;i++)
	{
		output += (rand() % m);
	}
	cout<<output<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
