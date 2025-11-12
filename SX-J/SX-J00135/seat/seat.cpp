#include<bits/stdc++.h>
using namespace std;
int mapp[20][20],n,m,a[110],b=1,s=0,as;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	as=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	while(true)
	{
		s++;
		mapp[i][j]=a[s];
		if(a[s]==as)
		{
			cout<<j<<" "<<i<<endl;
			return 0;
		}
		if(b==1)
		{
			if(i!=n)
			i++;
			else if(i==n)
			{
				b=2;
				j++;
			}
		}
		else if(b==2)
		{
			if(i!=1)
			i--;
			else if(i==1)
			{
				b=1;
				j++;
			}
		}
	}
	return 0;
}