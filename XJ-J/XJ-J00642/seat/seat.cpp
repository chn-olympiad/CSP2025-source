#include<bits/stdc++.h>
using namespace std;
int n,m,code[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>code[1];
	int r=code[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>code[i];
	}
	sort(code+2,code+n*m+1,cmp);
	int bl=2; 
	for(int a=1;a<=n;a++)
	{
		if(a%2==1)
		{
			for(int b=1;b<=m;b++)
			{
				if(code[bl]<r)
				{
					cout<<a<<" "<<b;
					return 0; 
				}
				bl++;
			}
		}
		if(a%2==0)
		{
			for(int b=m;b>=1;b--)
			{
				if(code[bl]<r)
				{
					cout<<a<<" "<<b;
					return 0; 
				}
				bl++;
			}
		}
	}
	return 0;
}
