#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int ans[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int tot=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[++tot]=(int)(s[i]-'0');
		}
	}
	sort(ans+1,ans+tot+1);
	for(int i=tot;i>=1;i--)
	{
		cout<<ans[i];
	}
	return 0;
}
