#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()]={0};
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[i]=s[i]-48;
			ans++;
		}
	}
	sort(a,a+s.size(),cmd);
	for(int i=0;i<ans;i++)
	   cout<<a[i];
	return 0;
}
