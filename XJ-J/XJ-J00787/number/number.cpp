#include<bits/stdc++.h>
using namespace std;
int nm,cnm;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10005],i=0;
	string b;
	cin>>b;
	for(;;)
	{
		a[i]=b[i]%10;
		b[i]=b[i]/10;
		if(b[i]<=0)
		{
			break;
		}
		i++;
	}
		int td=i;
		for(int j=0;j<td;j++)
	{
		for( i=0;i<td;i++)
		{
			if(a[i+1]>a[i])
			{
				nm=a[i];
				cnm=a[i+1];
				a[i]=cnm;
				a[i+1]=nm;
			}
		}
	}
	for(i=0;i<td;i++)
	{
		cout<<a[i];
	}
	return 0;
}
