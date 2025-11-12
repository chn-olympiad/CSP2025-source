#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int j=0,b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			b[j]=a[i]-48;
			j++;
		}
	}
	sort(b,b+j);
	j--;
	for(int i=j;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
