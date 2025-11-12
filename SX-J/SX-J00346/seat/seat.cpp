#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000006],he,x,tot=1,cnt=1,f;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	he=a[0];
	sort(a,a+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==he)
			x=i;
	}
	x=n*m-x;
	for(int i=2;i<=x;i++)
	{
		if(f==0)
			tot++;
		else
			tot--;
		if(tot>n&&f==0)
		{
			tot=n;
			cnt++;
			f=1;
		}
		if(tot<1&&f==1)
		{
			tot=1;
			cnt++;
			f=0;
		}
	}
	cout<<cnt<<" "<<tot;
//3 3
//94 95 96 97 98 99 100 93 92
	return 0;
}