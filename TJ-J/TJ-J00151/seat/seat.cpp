#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,s=1,t=1,num,sum,sub=1;
	int b[105]={0};
	int a[12][12];
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>num;
		b[num]=num;
		if(i==0)
		{
			sum=num;
		}
		
		
	}
	for(int i=100;i>=0;i--)
	{
		if(b[i]!=0)
		{
			if(b[i]==sum)
			{
				break;
			}
		sub++;
		}
	}
	for(int i=1;i<sub;i++)
	{
		if(t%2==1)
		{
			if(s%n==0)
			{
					t++;
			}
		
			
			else
			{
				s++;
			}
			
		}
		else
		{
			if(s%n==1)
			{
				t++;
			
			}
			
			else
			{
			s--;
			}
		}
		
	}
	cout<<t<<' '<<s;
	

	return 0;
	
	
	
	
}
