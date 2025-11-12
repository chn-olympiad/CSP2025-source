#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000006];
bool cmp(int a,int b)
{
	return a>b;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
