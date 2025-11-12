#include<bits/stdc++.h>
using namespace std;

int a[110];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	int num1=a[1];
	sort(a+1,a+sum+1,cmp);
	int temp;
	
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==num1) temp=i; 
	}
	int ansx=(temp-1)/n+1;
	int ansy;
	temp=(temp-1)%n+1;
	if(ansx%2==1) ansy=temp;
	else ansy=n+1-temp;
	cout<<ansx<<" "<<ansy;
	return 0;
}