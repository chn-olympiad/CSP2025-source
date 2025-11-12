#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int ans[1000100],k=0;
bool cmp(int x,int y)
{return x>y;}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++) if(s[i]>='0'&&s[i]<='9') ans[++k]=s[i]-'0';
	sort(ans+1,ans+k+1,cmp);
	for(int i=1;i<=k;i++) cout<<ans[i];
	return 0;
}
