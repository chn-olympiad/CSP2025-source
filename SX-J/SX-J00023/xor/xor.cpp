#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int sam;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int d=0;
		if(a[i]==m)
		{
			sam++;
			continue;
		}
		int t=i;
		for(int j=i+1;j<n;j++)
		{
			t^=a[j];
			if(t==m)
			{
				sam++;
				d=j;
			}
		}
		i=d;
	}
	cout<<sam;
	return 0;
}