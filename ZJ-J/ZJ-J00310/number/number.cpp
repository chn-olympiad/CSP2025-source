#include<bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
string st;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	if(st[i]>='0'&&st[i]<='9') a[++cnt]=st[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) putchar(char(a[i]+'0'));
	putchar('\n');
	return 0;
}
