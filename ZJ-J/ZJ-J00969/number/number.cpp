//bqq miaomiaomiao
//100
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}