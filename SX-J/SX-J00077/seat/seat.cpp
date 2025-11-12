#include<bits/stdc++.h>
using namespace std;
int n,m,a[110]={0},x=0;
double s=0;
int px(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[0];
	x=a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m,px);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==x)
		{
			s=((i*1.0+1.0)/n*1.0)*1.0;
			cout<<ceil(s*1.0)<<" ";
			if((i+1)%n==0)
			{
				if(((i+1)/n)%2==1)cout<<n;
				else              cout<<1;
			}
			else
			{
				if(((i+1)/n)%2==0)cout<<(i+1)%n;
				else              cout<<n-((i+1)%n-1);
			}
			return 0;
		}
	}
	return 0;
}