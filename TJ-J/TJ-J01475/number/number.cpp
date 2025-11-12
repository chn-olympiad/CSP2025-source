#include<bits/stdc++.h>
using namespace std;
int cnt[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(cnt[i])
		{
			cnt[i]--;
			cout<<i;
		}
	}
	return 0;
}
