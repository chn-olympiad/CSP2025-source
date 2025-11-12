#include<bits/stdc++.h>
using namespace std;
char s[1001000];
int ans[1001000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int n=strlen(s);
	int cnt=0;
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9') ans[++cnt]=s[i]-'0';
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<ans[i];
	return 0;
}