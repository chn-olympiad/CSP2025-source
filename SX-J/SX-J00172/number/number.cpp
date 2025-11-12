#include<bits/stdc++.h>
using namespace std;
bool d(int x,int y)
{
	if(x>y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
string s;
long long a[1000006],b=0;
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[b]=s[i];
			b++;
		}
	}
	sort(a,a+b,d);
	for(int i=0;i<b;i++)
	{
		cout<<(char)a[i];
	}
	return 0;
}