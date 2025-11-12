#include <bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long

string s;
ll len;
ll a[1000005];
ll cnt=0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len = s.length();
	For(i,0,len-1)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	dFor(i,cnt,1)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
