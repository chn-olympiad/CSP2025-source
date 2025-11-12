#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int ans[N],cnt;
bool flag;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[++cnt]=(s[i]-'0');
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(ans[i]==0&&!flag)
		{
			cout<<0;
			break;
		}
		else
		{
			cout<<ans[i];
			flag=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}