#include<bits/stdc++.h>
using namespace std;
int n,m,x,num;
int a[200];
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
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)x=i;
	}
	//cout<<x<<endl;
	int bb=x/n;
	if(x%n==0)
	{
		if(bb%2==0)
		{
			cout<<bb<<" "<<1;
		}
		else cout<<bb<<" "<<n;
	}
	else if(bb%2==0)
	{
		cout<<bb+1<<" "<<x%n;
	}
	else
	{
		cout<<bb+1<<" "<<n-x%n+1;
	}
	return 0;
}