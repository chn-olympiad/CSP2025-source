#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,p[4];
struct node{
	int a,b,c,maxn;
	bool f;
}s[N];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> s[i].a >> s[i].b >> s[i].c;
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=(n/2);i++)
			ans+=s[i].a;
		cout << ans << '\n';
	}
	return 0;
}