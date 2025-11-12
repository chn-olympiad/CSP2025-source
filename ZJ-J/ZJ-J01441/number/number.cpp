#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000005],len=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			a[++len]=str[i]-'0';
		}
	}
	sort(a+1,a+1+len);
	int i=len;
	while(a[i]==0&&i>=2)
	{
		i--;
	}
	for(i;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}