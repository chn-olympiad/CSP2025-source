#include<bits/stdc++.h>
using namespace std;
int n,b[1000009],s=0;
string a;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[s]=a[i]-'0';
			s++;
		}
	}
	sort(b,b+n,cmp);
	for(int i=0;i<s;i++)
	{
		cout<<b[i];
	}
	return 0;
}