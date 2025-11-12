#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+6;

int a[N];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int at=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')a[at++]=int(s[i]-'0');
	}
	sort(a+1,a+at);
	for(int i=at-1;i>=1;i--)cout<<a[i];
	return 0;
}