#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a=0;
	long long b=0;
	cin>>a;
	long long m=0;
	long long bug=0;
	cin>>b;
	int arr[100][100]={0};
	long long c=a*b;
	int ac[100000];
	long long p=0;
	for(int i=0;i<c;i++)
	{
		cin>>ac[i];
	}
	p=ac[0];
	for(int i=c-1;i>=0;i--)
	{
		for(int y=0;y<=i;y++)
		{
			if(ac[y]<ac[y+1])
			{
				bug=ac[y];
				ac[y]=ac[y+1];
				ac[y+1]=bug;
			}
		}
	}
	for(int i=0;i<b;i++)
	{
		if(i%2==0)
		{
			for(int y=0;y<a;y++)
		    {
				arr[i][y]=ac[m];
				m++;
				if(arr[i][y]==p)
				{
					cout<<i+1<<" "<<y+1;
					return 0;
				}
			}
		}
		if(i%2!=0)
		{
			for(int y=a-1;y>=0;y--)
			{
				arr[i][y]=ac[m];
				m++;
				if(arr[i][y]==p)
				{
					cout<<i+1<<" "<<y+1;
					return 0;
				}
			}
		}
		
	}
	return 0;
}
