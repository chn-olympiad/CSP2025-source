#include<bits/stdc++.h>
using namespace std;
char c[1010000];
int a[1010000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	int cnt=0;
	int l=strlen(c);
	for(int i=0;i<l;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[++cnt]=c[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
