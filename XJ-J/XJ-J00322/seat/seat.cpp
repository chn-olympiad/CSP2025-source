#include<bits/stdc++.h>
using namespace std;
int main()

{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m>>r;
	int a[m*n];
	a[1]=r;
	int sum=1;
	for(int i=1;i<=m*n-1;i++)
	{
		cin>>a[i+1];
		if(a[i]>r)
		{
			sum++;
		}
	}
	int t=sum/m;
	int y=sum%m;
	if(sum%m==0)
	{
		cout<<t<<" ";
		if(t%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<m;
		}
	}
	else
	{
		if(t%2!=0)
		{
			cout<<t+1<<" ";
			cout<<m-y+1;	 
		}
		else
		{
			cout<<t+1<<" "<<y; 
		}
	}
		
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
