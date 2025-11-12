#include<bits/stdc++.h>
using namespace std;
int used[109];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]<='9'&&s[i]>='0')
			used[(int)(s[i]-'0')]++;
	int flag=0;
	for(int i=9;i>=1;i--)
	{
		if(used[i]>0)
		{
			flag=1;
			while(used[i]>0)
			{
				cout<<i;
				used[i]--;
			}
		}
	}
	if(flag!=1)
		cout<<0;
	else
		while(used[0]>0)
		{
			cout<<0;
			used[0]--;
		}
	return 0;
}
