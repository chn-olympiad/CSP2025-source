//岳颢晨 SN-J00287 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
int a[100];
bool f(int a,int b)
{
	if(a>b)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,j,n1,m1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+100,f);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			j=i;
		}
	}
	if(j%m==0)
	{
		n1=j/m;
		if(j/m%2==0)
		{
			m1=m;
		}
		if(j/m%2!=0)
		{
			m1=1;
		}
	}
	if(j%m>0)
	{
		n1=j/m+1;
		if(n1%2!=0)
		{
			m1=(j-(n1-1)*m);
		}
		else
		{
			m1=m+1-(j-(n1-1)*m);
		}
	}
	cout<<n1<<" "<<m1;
	return 0;
}
