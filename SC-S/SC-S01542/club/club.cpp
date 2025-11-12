#include<bits/stdc++.h>
using namespace std;
int a[6][4][100001];
vector<int> b[4];
vector<int> c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
			b[1].clear();
		b[2].clear();
		b[3].clear();
		c.clear();
	int n;
	long long ma=0;
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][1][j];
		cin>>a[i][2][j];
		cin>>a[i][3][j];
		if(a[i][2][j]>=a[i][1][j]&&a[i][2][j]>=a[i][3][j])
		{
			ma+=a[i][2][j];
			b[2].push_back(j);
		}
		else if(a[i][1][j]>=a[i][2][j]&&a[i][1][j]>=a[i][3][j])
		{
			ma+=a[i][1][j];
			b[1].push_back(j);
		}
		else
		{
			ma+=a[i][3][j];
			b[3].push_back(j);
		}
	}
	if(b[1].size()>n/2)
	{
	for(int j=0;j<b[1].size();j++)
	{
	c.push_back(a[i][1][b[1][j]]-max(a[i][2][b[1][j]],a[i][3][b[1][j]]));	
	}
	sort(c.begin(),c.end());
	for(int j=0;j<b[1].size()-(n/2);j++)
	{
		ma-=c[j];
			}		
	}
	else if(b[2].size()>n/2)
	{
			for(int j=0;j<b[2].size();j++)
	{
	c.push_back(a[i][2][b[2][j]]-max(a[i][1][b[2][j]],a[i][3][b[2][j]]));	
	}
	sort(c.begin(),c.end());
	for(int j=0;j<b[2].size()-(n/2);j++)
	{
		ma-=c[j];
			}
	}
	else if(b[3].size()>n/2)
	{
		for(int j=0;j<b[3].size();j++)
	{
	c.push_back(a[i][3][b[3][j]]-max(a[i][2][b[3][j]],a[i][1][b[3][j]]));	
	}
	sort(c.begin(),c.end());
	for(int j=0;j<b[3].size()-(n/2);j++)
	{
		ma-=c[j];
			}	
	}
		cout<<ma<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 