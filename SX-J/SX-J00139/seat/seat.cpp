#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
bool cmp(int a,int b)
{
	return a>b;
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
	int ct=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==ct)
		{
			int l=i/n;
			int ol=l;
			if(i%n!=0)
			{
				l++;
			}
			int h=0;
			if(l%2==1)
			{
				h=i-ol*n;
				if(h==0)
				{
					h=m;
				}
			}
			else
			{
				h=m-i+ol*n+1;
			}
			cout<<l<<' '<<h;
			return 0;
		}
	}
	return 0;
}