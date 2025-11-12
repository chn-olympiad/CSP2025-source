#include<bits/stdc++.h>
using namespace std;
string a;
int b[30],l,n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		b[a[i]-'0']+=1;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		cout<<i;
	}
	return 0;
}
