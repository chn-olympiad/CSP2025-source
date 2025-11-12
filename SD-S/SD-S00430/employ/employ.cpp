#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
const int Mod = 998244353;
int a[11],c[N];
int n,m,ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) a[i]=i,cin>>c[i];
	do
	{
		int cnt=0,p=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||c[a[i]]<=cnt)
			{
				cnt++;
			}
			else p++;
		}
		if(p>=m) ans++,ans%=Mod;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
//freopen()
// 暴力打满，跑路
// uid 704139
// 膜拜 UG,COB，Fwb
// Afoed
/*
祝各位巨佬进入省队

祝 kaka 和 anll 白头偕老

我常常追忆过去……

希望能上迷惑行为打赏 
*/ 
