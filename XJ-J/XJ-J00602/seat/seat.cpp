#include<bits/stdc++.h>
using namespace std;
long long a[110],n,m,a1,wz,l;
double l1;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m*n,cmp);
	for(int i=1;i<=m*n-1;i++)
	{
		if(a1>a[i])
		{
			wz=i;
			break;
		}
	}	
	l=wz/n;
	l1=wz*1.0/n;
	if(l1<=1)
	{
		cout<<'1'<<" ";
		l=1;
	}
	else
	{
		if(l1==l)
		{
			cout<<wz/n<<' ';
		}
		else
		{
			cout<<wz/n+1<<' ';
			l++;
		}
	}
	if(l%2==1)
	{
		if(wz%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<wz%n;
		}
	}
	else
	{
		if(wz%n==0)
		{
			cout<<'1';
		}
		else
		{
			cout<<n-(wz%n)+1;
		}
	}
	return 0;
}
