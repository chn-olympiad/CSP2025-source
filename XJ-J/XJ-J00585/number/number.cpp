#include<bits/stdc++.h>
using namespace std;
string a;
long long int i,n,j,b[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j,greater<int>());
	for(i=0;i<j;i++)
	{
		cout<<b[i];
	}
	return 0;
}
