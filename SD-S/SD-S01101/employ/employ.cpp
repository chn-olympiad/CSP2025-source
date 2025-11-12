#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int N=1e6+5;
int n,m,a[N],ans,c[N];
string s;
void solve()
{
	cin>>n>>m;
	cin>>s;
	For(i,1,n)cin>>c[i];
	For(i,1,n)a[i]=i;
	do{
		int t=0,x=0;
		For(i,1,n)
		{
			if(x>=c[a[i]])
			{
				x++;
				continue;
			}
			if(s[i-1]=='1')t++;
			else x++;
		}
		if(t>=m)ans++;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

