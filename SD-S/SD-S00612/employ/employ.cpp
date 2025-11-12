#include <bits/stdc++.h> 
#define endl '\n'
using namespace std;
const int MOD=998244353;
int n,m,c[505],num,num2;
long long ans=1;
string s;
bool x;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='1') num++;
	}
	for (int i=1;i<=n;i++)
	{
		cin >> c[i];
		if(c[i]==0) num2++;
	}
	if(num==s.length())
	{
		for (int i=1;i<=n-num2+1;i++)
		{
			ans=(ans*i)%MOD;
		}
			
	}
	else if(m==1)
	{
		for (int i=1;i<=n;i++)
			ans=(ans*i)%MOD;
	}
	if(m>n-num2)
	{
		cout << 0;
		return 0;
	 }
	cout << ans;
	return 0;
}
