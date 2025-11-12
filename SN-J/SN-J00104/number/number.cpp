#include<bits/stdc++.h>
std::string s;
inline bool cmp(char x,char y)
{
	return x>y;
}
inline void solve()
{
	std::cin>>s;
	std::sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			std::cout<<s[i];
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}
