#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[10005][4],a1[10005];
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		a1[i]=a[i][1];
	}
	sort(a1,1,n);
}
