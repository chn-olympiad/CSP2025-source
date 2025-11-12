#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
bool xor_l_r(int l,int r)
{
	int sum=a[l];
	for(int i=l+1;i<=r;i++)
	{
		sum^=a[i];
	}
	return sum==m;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n-maxx;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(xor_l_r(i,j))
			{
				i=j;
				sum++;
				break;
			}
		}
	}
	cout<<sum<<'\n';
	return 0;
}
