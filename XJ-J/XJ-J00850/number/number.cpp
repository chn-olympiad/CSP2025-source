#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int i,j=0;
	cin>>a;
	for(i=0;i<=a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
	for(i=j-1;i>=0;i--)
	cout<<b[i];
	return 0;
} 
