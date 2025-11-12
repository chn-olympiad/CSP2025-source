#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],r,num;  //行数n 列数m
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
		if(i==1)
		{
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r){
			num=i;
		}
	}
	int m1=num/n;
	int n1=num%n;
	if(n1==0)
	{
		if(m1%2==0)
		{
			cout<<m1<<" 0";
		}
		else{
			cout<<m1<<" "<<n;
		}
	}
	else
	{
		if(m1%2==0)
		{
			cout<<m1+1<<" "<<n1;
		}
		else{
			cout<<m1+1<<" "<<n-n1+1;
		}
		
	}
    
	return 0;
}

