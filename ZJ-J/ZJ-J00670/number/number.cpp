#include<bits/stdc++.h>
using namespace std;
int tot,a[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)
		cout<<a[i];
	return 0;
}