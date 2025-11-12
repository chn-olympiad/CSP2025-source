#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010];
string c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int i=0;i<c.size();i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[n++]=c[i]-'0';
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
