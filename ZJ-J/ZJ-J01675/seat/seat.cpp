#include<bits/stdc++.h>
using namespace std;
long long n,m,s,s1;
struct BYM
{
	long long shu,wei;
}a[1000100];
bool cmp(BYM x,BYM y)
{
	return x.shu>y.shu;
}
int main( )
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long s=n*m;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i].shu;
		a[i].wei=i;
	}
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++)
	{
		//cout<<a[i].shu<<' ';
		if(a[i].wei==1)
		{
			s1=i;
		}
	}
	if(s1%n==0)
	{
		cout<<s1/n<<' ';
		if((s1/n)%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
	}
	else
	{
		cout<<s1/n+1<<' ';
		if((s1/n+1)%2==1)
		{
			cout<<s1-(s1/n*n);
		}
		else
		{
			cout<<n-(s1-(s1/n*n))+1;
		}
	}
	return 0;
}
//CCF NB
