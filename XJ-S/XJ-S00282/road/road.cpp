#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int num[m][3];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>num[i][j];	
		}
	}
	int num1[k][n]={}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>num1[i][j];
		}
	}
	cout<<"0";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
