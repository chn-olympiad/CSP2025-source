#include <bits/stdc++.h>
using namespace std;
string n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100005],sum=0,num=1;
	cin>>n;
	for(int i=0;i<n.length();i++)
	{
		if((string[i]<'a') || (string[i]>'z'))
		{
			a[num]=string[i];
		}
	    num++;
	}
	int m=1;
	sort(a,a+1,a+n+1);
	for(int i=sum;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			m*=10;
		}
	}
	sum+=a[i]*m;
	cout<< sum;
	return 0;
}
