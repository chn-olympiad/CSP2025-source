#include<bits/stdc++.h>
using namespace std;
long long q[1100000],x;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9') q[++x]=s[i]-'0';
	}
	sort(q+1,q+1+x);
	for(int i=x;i>=1;i--) cout<<q[i];
	return 0;
}