#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> s;
	memset(a,-1,sizeof(a));
	int k=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k+1;i++)
	{
		if(a[i]>=0)
		{
			cout<<a[i];
		}
	}
	return 0;
}
