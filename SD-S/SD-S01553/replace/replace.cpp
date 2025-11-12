#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
inline LL read()
{
	int num = 0,sign = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9')sign = ch == '-'?-1:1,ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+ch-'0',ch = getchar();
	return sign>0?num:-num;
}
const int MAXN = 2e5+8;
int n,q;
string s[MAXN][2],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(),q = read();
	for(int i = 1;i <= n;i++)cin>>s[i][0]>>s[i][1];
	for(int i = 1;i <= q;i++)
	{
		cin>>t1>>t2;
		int ans = 0;
		for(int i = 0;i < t1.size();i++)
		{
			for(int j = 1;j <= n;j++)
			{
				int a = s[j][0].size();
				if(i+1 >= s[j][0].size()&&t1.substr(i+1-s[j][0].size(),i) == s[j][0]&&t1.substr(0,max(0,i-a))+s[j][1]+t1.substr(min(n,i+1),n) == t2);
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
