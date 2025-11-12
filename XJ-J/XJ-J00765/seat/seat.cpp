#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n*m];
	for(int a=0;a<n*m;a++)
		cin>>arr[a];
	int R=arr[0];
	sort(arr,arr+n*m,cmp);
	int c,r;
	for(int a=0;a<n*m;a++)
	{
		if(arr[a]==R)
		{
			c=ceil((double)(a+1)/m);
			if(c%2!=0)
			{
				if((a+1)%m==0)
					r=m;
				else
					r=(a+1)%m;
			}
			else if(c%2==0)
			{
				if((a+1)%m==0)
					r=0;
				else
					r=m+1-((a+1)%m);
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

