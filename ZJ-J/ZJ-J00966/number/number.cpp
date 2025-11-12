#include<bits/stdc++.h>
#define f(i,l,r) for(int i=(l);i<=(r);++i)
#define g(i,l,r) for(int i=(l);i>=(r);--i)
using namespace std;
string s;
int t[15];
int slen;
int main(){
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	slen = s.size();
	for(int i = 0;i<slen;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			t[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--)
	{
		while(t[i])
		{
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}

