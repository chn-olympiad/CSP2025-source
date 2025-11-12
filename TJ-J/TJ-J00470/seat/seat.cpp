#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return y<x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b=n*m;
	int a[b];
	for(int i=1;i<=b;i++)
	{
		cin>>a[i];
	}
	int mar=a[1];
	int t=0;
	sort(a+1,a+b+1,cmp);
	/*for(int i=1;i<=b;i++)
	{
		cout<<a[i]<<" ";
	}*/ 
	for(int i=1;i<=b;i++)
	{
		if(a[i]==mar)t=i;
	}
	//cout<<"___"<<t<<"___";
	if(t<=n)cout<<1<<" "<<t;
	else if(t%(2*n)==n)cout<<t/n<<" "<<n;
	else if(t%(2*n)==0)cout<<t/n<<" "<<1;
	else if((t%n)==1 && t-1==n)cout<<(t/n)+1<<" "<<n;
	else if((t%n)==1 && (t-1)%2*n==0)cout<<(t/n)+1<<" "<<1;
	else if((t%n)==1 && (t-1)%2*n==n)cout<<(t/n)+1<<" "<<n;
	else cout<<(t/n)+1<<" "<<n-(t%n);
	return 0;
}
