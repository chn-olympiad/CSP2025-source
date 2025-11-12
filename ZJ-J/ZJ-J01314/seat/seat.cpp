#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101],ans,num=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		if(i==1)
		{
			ans=x;
		}
		else if(x>ans)
		{
			num++;
		}
	}
	if(num%m!=0)
	{
		cout<<num/m+1<<" "<<num%m;
	}
	else
	{
		cout<<num/m<<" "<<n;
	}
	return 0;
}
