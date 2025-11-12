#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int  cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i,j=1;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
