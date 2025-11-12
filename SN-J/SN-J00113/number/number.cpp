#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1005];
	int sum=1;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a+1,a+sum,cmp);
	int q=0;
	for(int i=1;i<sum;i++)
	{
		cout<<a[i];
		q=1;
	}
	return 0;
}
