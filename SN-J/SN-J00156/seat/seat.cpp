#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,x,y=0,r,j,a,b,z=1;
	cin>>n>>m;
	int seat[m][n];
	int s[n*m];
	cin>>r;
	s[0]=r;
	for(int i=1;i<n*m;i++)
	{
		cin>>s[i];
	}
	for(j=1;j<=m*n;j++)
	{
		for(int i=0;i<m*n-1;i++)
		{
			if(s[i]<s[i+1])
			{
				swap(s[i],s[i+1]);
			}
		}
	}
	j=0;
	for(int i=0;i<m;i++)
	{
		
	}
	//cout<<a<<" "<<b;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
