#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

int n,m,a[N],r;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int f=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			f=i;
		}
	}
	int l=-1,h=-1;
	if(f<=n)
	{
		cout<<"1 "<<f;
		return 0;
	}
	if(f%n==0)
	{
		l=f/n;
		h=(f%2==0)?1:n;
	}
	else
	{
		l=f/n+1;
		h=((f/n)%2==0)?f%n:n-f%n+1;
	}
	/*
	i%n==0   l=i/n   ;; i%2==0 ? h=1:h=n 
	i%n==1~n-1 l=i/n+1 ;; i/n%2==0 ? h=i%n:h=n-i%n+1
	*/
	cout<<l<<' '<<h;
	return 0;
}
