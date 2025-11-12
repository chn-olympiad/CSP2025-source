#include <bits/stdc++.h>
using namespace std;
string s,ans;
int a[1000010],tt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++tt]=(int)s[i]-'0';
		}
	}
	sort(a+1,a+tt+1,greater<int>());
	for(int i=1;i<=tt;i++) ans+=(char)a[i]+'0';
	cout<<ans;
	return 0;
}