#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	char b[1000000];
	for(int i=0;i<s.size();i++)
	{
		
		if(s[i]>=97&&s[i]<=122)
		{
		}
		else
		{
			b[ans]=s[i];
			ans++;
		}
	}
	sort(b,b+ans);
	for(int i=ans-1;i>=0;i--)
	{
			cout<<b[i];
	}
}
