#include<bits/stdc++.h>
using namespace std;
string s;char c;
int n,i,cnt[10],rp;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	rp++;
	for(i=0;i<s.size();i++)
	{c=s[i];if(c<='9'&&c>='0')cnt[c-'0']++;}
	for(i=9;i>=0;i--)while(cnt[i]--)cout<<i;
	return 0;
}
