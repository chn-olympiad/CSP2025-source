#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ans;
	for(int i=0;i<s.size();i++)
	{
		if('a'<=s[i]&&s[i]<='z')
		{
			continue;
		}
		else
		{
			ans+=s[i];
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=i+1;j<ans.size();j++)
		{
			if(ans[i]<ans[j])
			{
				swap(ans[i],ans[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
