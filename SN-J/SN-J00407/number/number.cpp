#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std;
string s;
int l,cnt;
int a[1000010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if('0'<=s[i] && '9'>=s[i])
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
//		cout<<a[i];
		printf("%.ld",a[i]);
	}
	return 0;
}
