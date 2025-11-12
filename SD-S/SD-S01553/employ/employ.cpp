#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 512;
const int MOD = 998244353;
inline int read()
{
	int num = 0,sign = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9')sign = ch == '-'?-1:1,ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+ch-'0',ch = getchar();
	return sign>0?num:-num;
}
int m,n,c[MAXN],ans = 1,cnt,cnt0;
bool s[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++)
	{
		char ch;
		cin>>ch;
		cnt += s[i] = ch-'0';
	}
	for(int i = 1;i <= n;i++)c[i] = read(),cnt0 += c[i]==0;
	if(cnt < m)cout<<0;
	for(int i = 1;i <= n;i++)
	{
		ans = (ans*i)%MOD;
	}
	cout<<ans;
	return 0;
}
