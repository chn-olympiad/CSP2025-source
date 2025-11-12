#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],z,rjq,sot,lie,hang;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++)
	{
		cin>>a[i];
	}
	rjq=a[1];
	sort(a+1,a+1+z,greater<int>());
	for(int i=1;i<=z;i++)
	{
		//cout<<a[i]<<" ";
		if(a[i]==rjq)
		{
			sot=i;
			break;
		}
	}
	//cout<<sot<<endl;
	if(sot%n!=0)
	{
		lie=sot/n+1;
	}
	else
	{
		lie=sot/n;
	}
	if(lie%2==1)
	{
		hang=sot%n;
		if(hang==0)
		{
			hang=n;
		}
	}
	else
	{
		if(sot%n==0)
		{
			hang=1;
		}
	
		else hang=n-(sot%n)+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}

