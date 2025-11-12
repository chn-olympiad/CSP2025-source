#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,ans;
int n;
bool cmp(char x,char y)
{
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		cout<<s[i];
	}
	return 0;
}