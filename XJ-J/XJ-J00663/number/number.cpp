#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size()-1,j=1;
	for(int i=1;i<=l;i++)
	{
		if(a[i]>a[i-1])
		{
			swap(a[i],a[i-1]);
		}
		if(a[i]>='a' && a[i]<='z')
		{
			a[i]=' ';
		}
	}
	cout<<a;
	return 0;
}
