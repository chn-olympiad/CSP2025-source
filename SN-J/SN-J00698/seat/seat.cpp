#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1000005];
int sum;
int h,l,s;
int x;


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>num[i];
	}
	int x=num[1];
	sort(num+1,num+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(num[i]>=x)
		{
			sum++;
		}
		else if(num[i]<=x)
		{
			break;
		}
	}
	if(sum%n!=0)
	{
		l=sum/n+1;
	}
	else{
		l=sum/n;
	}
	if(l%2==0)
	{
		//h=n-(sum-(l-1)*n)+1;
		h=l*n-sum+1;
	}
	else
	{
		h=sum-(l-1)*n;
	}
	cout<<l<<" "<<h;
	return 0;
}
