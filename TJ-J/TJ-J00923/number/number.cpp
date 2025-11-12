#include <bits/stdc++.h>
using namespace std;
char c[1100000];
int a[1100000];
int cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	for(int i=0;c[i]!='\0';++i)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			++cnt;
			a[cnt]=c[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;++i)
	{
		cout<<a[i];
	}
	return 0;
}
