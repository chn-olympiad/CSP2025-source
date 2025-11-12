#include<bits/stdc++.h>
using namespace std;
long long int a[1000005];
bool cmp(long long int x,long long int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long int ls,i,x=0;
	cin>>s;
	ls=s.size();
	for(i=0;i<ls;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a+0,a+x,cmp);
	for(i=0;i<x;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
