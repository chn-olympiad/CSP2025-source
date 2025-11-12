#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
string s;
int v[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	f(i,0,s.size()-1)
	    if(isdigit(s[i]))v[s[i]-'0']++;
	d(i,9,0)
		f(j,1,v[i])cout<<i;
	return 0;
}
