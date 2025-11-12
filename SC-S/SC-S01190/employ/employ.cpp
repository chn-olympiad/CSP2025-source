#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=5e2+10;
const int mod=998244353;

int n,m;
int e[N],a[N];
int p[N];
string s;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=" "+s;
	rep(i,1,n) cin>>a[i],p[i]=i;
	int cnt=0;
	do {
		int no=0,ans=0;
		rep(i,1,n) {
			if (no>=a[p[i]]) no++;
			else {
				if (s[i]=='1') ans++;
				else no++;
			}
		}
		cnt=(cnt+(ans>=m))%mod;
	}while (next_permutation(p+1,p+n+1));
	cout<<cnt<<endl;
	return 0;
}
/*
对于所有 c[i] ,sum[i]<c[i]

f[i][j] 表示前 i 天，录用了 j 个人的方案数

3 2
101
1 1 2

2
*/