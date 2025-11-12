#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
int a[N];
string s;
void teshu1()
{
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout << ans;
}
void teshu2()
{
	int f=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			cout << 0 << endl;
			f=0;
			break;
		}
	}
	if(f==1)
	{
		teshu1();
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int x=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=0)
		{
			x++;
		}
	}
	int f=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			f=0;
		}
	}
	if(f==1)
	{
		if(x<m)
		{
			cout << 0;
			return 0;
		}
		teshu1();
		return 0;
	}
	if(m==n)
	{
		if(x!=n)
		{
			cout << 0;
			return 0;
		}
		teshu2();
	}
	cout << 0;
	return 0;
}
//Ren5Jie4Di4Ling5%
