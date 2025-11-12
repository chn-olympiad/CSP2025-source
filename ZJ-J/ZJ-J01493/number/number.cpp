#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,t=0;
	string s;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}