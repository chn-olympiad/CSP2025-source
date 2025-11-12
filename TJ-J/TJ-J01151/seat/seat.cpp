#include<bits/stdc++.h>
using namespace std;
int seats[10000][10000];
int num[100000];
bool flag=0;
int t;
int x,y,cnt,sum,r=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>seats[i][j];
			r++;
			seats[i][j]=num[r];
		}
	}
	cnt=seats[1][1];
	for(int i=1;i<=a*b;i++)
	{
		flag=0;
		while(flag=1)
		{
			if(num[i]>=num[i-1])
			{
				t=num[i];
				num[i]=num[i-1];
				num[i-1]=t;
			}
			else
			{
				flag=1;
			}
		}
	}
	r=0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			r++;
			seats[i][j]=num[r];
			if(seats[i][j]==cnt)
			{
				cout<<i<<j;
				return 0;
			}
		}
	}
	return 0;
	/*
	for(int i=1;i<=a*b;i++)
	{
		cin>>seats[i];
		seats[1]=cnt;
		flag=0;
		while(flag=1)
		{
			if(seats[i]>=seats[i-1])
			{
				t=seats[i];
				seats[i]=seats[i-1];
				seats[i-1]=t;
			}
			else
			{
				flag=1;
			}
		}
	}
	for(int i=1;i<=a*b;i++)
	{
		if(seats[i]==cnt)
		{
			sum=i;
			break;
		}
	}
	for(int i=1;i<=sum;i++)
	{
		if(y%2==0)
		{
			x--;
		}
		else if(y%2!=0)
		{
			x++;
		}
		else if(i>b)
		{
			y++;
		}
	}
	cout<<x<<" "<<y;
	*/
	fclose(stdin);
	fclose(stdout);
}
