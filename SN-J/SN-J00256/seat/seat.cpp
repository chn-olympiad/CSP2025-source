#include<bits/stdc++.h>
using namespace std;
int n,m;
int a;
int sum;
int q;
int cnt=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    sum=n*m;
    for(int i=1;i<=sum;i++)
    {
    	if(i==1) cin>>a;
    	else cin>>q;
    	if(q>a)cnt++;
	}
	int c=cnt/m,c1=cnt%m,r=cnt/n,r1=cnt%n;
	if(c1!=0) cout<<c+1<<' ';
	else cout<<c<<' ';
	if(r%2==0)
	{
		if(r1==0) cout<<1;
		else cout<<r1;
	}
	else
	{
		if(r1==0) cout<<n;
		else cout<<n-r1+1;
	}
	return 0;
}
