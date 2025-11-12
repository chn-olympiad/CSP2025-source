#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int cnt,n;
int shu[1000010];

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			shu[++cnt]=(int)s[i]-'0';
		}
	}
	sort(shu+1,shu+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<shu[i];
	}
	return 0;
}
