#include<bits/stdc++.h>
using namespace std;
const int slen=1e6+10;
string s;
int ans[slen];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int j=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(ans,ans+j+1);
	for(int i=j;i>=0;i--)
		cout<<ans[i];
	return 0;
}