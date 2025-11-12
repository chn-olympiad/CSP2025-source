#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a1;
	cin>>a1;
	int a[1005];
	int cnt=1;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>a[i];
		if(a[i]>a1)
		{
			cnt++;
		}
	}
	if(cnt<=m)
	{
		cout<<"1"<<" "<<cnt;
		return 0;
	}
	else
	{
		int c=cnt/m;
		int cc=cnt%m;
		if(cc!=0)
		{
			c=c+1;
		}
			cout<<c<<" ";
			if(c%2==0)
			{
				if(cc==0)
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<m-cc+1;
					return 0;
				}
			}
			else
			{
				if(cc==0)
				{
					cout<<m;
					return 0;
				}
				else
				{
					cout<<cc;
					return 0;
				}
			}
	}
	return 0;
}
