#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[1001];
int n,m;
bool cmp(int s1,int s2)
{
	return s1>s2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int sum=b[1];
	bool x=true;
	sort(b+1,b+1+n*m,cmp);
	int cnt=1;
	for(int j=1;j<=n;j++)
	{
		if(x==true)
		{
			int i=1;
			for(i=1;i<=m;i++)
			{
				if(b[cnt]==sum)
				{
					cout<<j<<" "<<i;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt++;
			}
			x=false;
		}
		else
		{
			int i=m;
			for(i=m;i>=1;i--)
			{
				if(b[cnt]==sum)
				{
					cout<<j<<" "<<i;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				cnt++;
			}
			x=true;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
