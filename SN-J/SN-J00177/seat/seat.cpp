#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
		
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c,r,s,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			num=i;
			break;
		}
	}
	c=num/n;
	r=num%n;
	if(r!=0)
	{
		c+=1;
	 } 
	if(r==0)
	{
		r=n;
	}
	if(c%2==0)
	 {
	 	r=n+1-r;
	 }
	cout<<c<<' '<<r;
	return 0;
 } 
