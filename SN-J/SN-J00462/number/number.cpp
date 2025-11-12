#include<bits/stdc++.h>
using namespace std;
char c;
long long a[1000005],i,t;
bool cmp(int a,int b)
{
	return a>b;
}
bool awa(char x)
{
	int s=x-'0';
	if(s<=9&&s>=0)
	return 1;
	return 0;
}
string b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int l=b.size();
	for(int j=0;j<=l;j++)
	{
		c=b[j];
		if(awa(c))
		{
			a[i++]=c-'0';
			t++;
		}
	}
	sort(a,a+i,cmp);
	for(int j=0;j<t;j++)
	{
		cout<<a[j];
	}
	return 0;
}
