#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int num=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			num=i;
		}
	}
	int ans1=ceil((double)num/n),ans2=0;
	if(num%n==0)
	{
		if(ans1%2==1) ans2=n;
		else ans2=1;
	}
	else
	{
		if(ans1%2==1) ans2=num%n;
		else ans2=n-num%n+1;
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0; 
}
