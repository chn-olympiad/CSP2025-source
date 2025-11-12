#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
constexpr int N=509;
int s[N],c[N],p[N],ans[N];
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n,m;
	string st;
	cin>>n>>m;
	cin>>st;
	F(i,1,n)s[i]=st[i-1]-'0';
	F(i,1,n)cin>>c[i];
	F(i,1,n)p[i]=i;
	do
	{
		int t=0;
		F(i,1,n)
		{
			int x=p[i];
			if(s[i]==1&&c[x]>t);
			else t++;
		}
		ans[n-t]++;
	}while(next_permutation(p+1,p+n+1));
	F(i,0,n)cout<<ans[i]<<"\n";
	int sum=0;
	F(i,m,n)sum+=ans[i];
	cout<<sum<<'\n';
	return 0;
}
