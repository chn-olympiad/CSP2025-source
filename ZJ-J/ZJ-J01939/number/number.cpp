#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1000005];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	string s;
	cin>>s;
	int len=s.size(),cnt=0;
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[i+1]=s[i]-'0';
			cnt++;
		}
			
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
