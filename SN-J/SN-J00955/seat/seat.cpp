#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("seat","r",stdin);
	freopen("seat","n",stdout);
	int c[1000000000];
	int z[1100];
	int n,m;
	int h=0,l=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
		z[0]=c[0];
	}
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(z[0]<=c[i])
			{
				l++;
				if(l>m)
				{
					h+=1;
					l=1;
				} 
			}
			if(z[0]>c[i])
			{
				h=1;
				l=1;
				cout<<h<<l;
				return 0;
			}
		}
	} 
	cout<<h<<l;
	return 0;
}
