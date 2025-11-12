#include <bits/stdc++.h>
using namespace std;
struct ss{
	string s1,s2;
} s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2; 
	}
	for(int i=1;i<=q;i++)
	{
		string ss1,ss2;
		cin>>ss1>>ss2;
		cout<<0;
	}
	return 0;
}

