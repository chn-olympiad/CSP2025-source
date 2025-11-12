#include<bits/stdc++.h>
using namespace std;
long long int x[1000010];
int c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<='9' &&a[i]>='0')
		{
			x[c]=a[i]-'0';
			c++;
		}
	}
	sort(x,x+1);
	for(int i=0;i<c;i++)
	{
		cout<<x[i];
	}
	return 0;
}
