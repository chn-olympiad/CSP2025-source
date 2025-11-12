#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long b[N],j=0,maxx=-1;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j++]=a[i]-'0';
			maxx=max(b[j-1],maxx);
		}
	}
	sort(b,b+j);
	if(maxx==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<j;i++)
	{
		cout<<b[j-i-1];
	}
	return 0;
}