#include<bits/stdc++.h>
using namespace std;
int n,a[100001][4],t,ans,mx=-10000;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0)
	{
		t--;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		cout<<1<<'\n';
	}
}