#include <bits/stdc++.h>
#define int long long
using namespace std;
int i,j,l,f[20];
char s[1000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;l=strlen(s+1);
	for(i=1;i<=l;i++)
		if('0'<=s[i]&&s[i]<='9')
			f[s[i]-'0']++;
	for(i=9;i>=0;i--)
		for(j=1;j<=f[i];j++)
			cout<<i;
}
