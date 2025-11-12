#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int cnt,a[1000006];
bool cmp(int X,int Y)
{
	return X>Y;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	s=" "+s;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return  0;
}
