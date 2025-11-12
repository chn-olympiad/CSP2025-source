#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n;
 int t[20];
 char c[1000010];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>(c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++)if('0'<=c[i]&&c[i]<='9')t[c[i]-'0']++;
	for(int i=9;i>=0;i--)while(t[i]--)cout<<i;
	return 0;
}
