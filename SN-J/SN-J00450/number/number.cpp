#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+15;
int a[N];
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
	int len = s.size();
	int cnt = 0;
	for(int i = 0;i<len;i++)
	{
		char ch = s[i];
		if(ch>='0'&&ch<='9')
		{
			a[++cnt]=ch-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++) cout<<a[i];
	return 0;
 } 
