#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,g,i,j;
bool flag=true;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s[m][n];
	int x[n*m+10];
	for(int a=1;a<=n*m;a++)
	{
		cin>>x[a];
	}
	g=x[1];
	sort(x,x+m*n,cmp);
	for(i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(j=1;j<=n;j++)
			{
				s[j][i]=x[j];	
			}
			if(x[j]==g)
			{
				c=j;
				r=i;
				flag=false;
				break;
			}	
		}
		else if(i%2==0)
		{
			for(j=n;j>=1;j--)
			{
				s[j][i]=x[j];
			}
			if(x[j]==g)
			{
				c=j;
				r=i;
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
