#include<bits/stdc++.h>

using namespace std;
int n,m,a[1000];
bool cmd( int a,int b)
{
	return (a>b);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1)
	{
		cout<<m<<' '<<n;
		return 0;
	}
	else if(a[1]==n*m)
	{
		cout<<1<<' '<<1;
		return 0;
	}
	int s=a[1],fl;
	sort (a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			fl=i;
		}
	}
	if(m==1)
	{
		cout<<fl<<' '<<1;
	}
	else if(n==1)
	{
		cout<<1<<' '<<fl;
	}
	return 0;
}
//sto sto shangshanruoshui,rp++ orz orz 
//sto sto shangshanruoshui,rp++ orz orz
//sto sto shangshanruoshui,rp++ orz orz
//freopen("seat.in","r",stdin);(zhapian)
