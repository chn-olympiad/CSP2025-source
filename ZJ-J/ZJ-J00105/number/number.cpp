#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int b=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b,cmp);
	for(int i=0;i<b;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
