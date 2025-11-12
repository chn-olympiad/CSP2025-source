#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,p[505],c[505],ans=0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0') cnt++;
			else if(cnt>=c[p[i]]) cnt++;
		if(n-cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
