#include<bits/stdc++.h>
using namespace std;
int a[10000000][10000000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	return 0;
}
