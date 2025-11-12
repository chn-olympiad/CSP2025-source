#include<bits/stdc++.h>
using namespace std;
long long int n,b1,b2,b3,a[50005],all,big; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		b1=a[1];
		b2=a[2];
		b3=a[3];
		all=(b1+b2+b3);
		big=max(b1,max(b2,b3));
		
		if(all>(big*2))
		cout<<'1';	
		else
		cout<<'0';
	} 
	return 0;
}
 
