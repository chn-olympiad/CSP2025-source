#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int cnt,a[1000005];
bool cmp(int l,int r)
{
	return l>r;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;++i)
	    cout<<a[i];
	return 0;
}
