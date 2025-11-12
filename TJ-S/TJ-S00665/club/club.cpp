#include<bits/stdc++.h>
using namespace std;
int l,e[1010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>l;
	for(int w=0;w<l;w++)
	{
		int n,a[1010][3];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			int max=0;
			for(int j=0;j<3;j++)
			{
				if(max<a[i][j])
				{
					max=a[i][j];
				}
			}
			e[w]+=max;
		}
	}
	for(int i=0;i<l;i++)
	{
		cout<<e[i]<<endl;
	}
	return 0;
}
