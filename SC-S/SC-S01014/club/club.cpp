#include <bits/stdc++.h>
//#define int long long
using namespace std;
int t,n;
struct node
{
	int a,b,c;
}d[100005];
inline int dfs(int i,int a,int b,int c)
{
	if(i==n+1||a+b+c>n)
		return 0;
	int sb=0;
	if(a<n/2)
		sb=max(sb,dfs(i+1,a+1,b,c)+d[i].a);
	if(b<n/2)
		sb=max(sb,dfs(i+1,a,b+1,c)+d[i].b);
	if(c<n/2)
		sb=max(sb,dfs(i+1,a,b,c+1)+d[i].c);
	return sb;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>d[i].a>>d[i].b>>d[i].c;
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
} 