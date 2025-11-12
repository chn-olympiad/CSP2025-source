//ALL FOR MYSELF, NOT ANYONE ELSE
#include<bits/stdc++.h>
//#define TERRY_MC
#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
const int N=505,MOD=998244353;
int n,m,c[N];
bitset<N> s;//当bool数组用吧 
char ch;
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef TERRY_MC
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(s.none()) {
		cout<<0<<endl;
	}
	if(m==1) {//依然很假 
		int ans=0,fac=1,fircan=1;
		for(int i=2;i<n;i++) {
			fac*=i;
			fac%=MOD; 
		}
		for(int i=1;i<=n;i++) {
			if(s[i]) {
				fircan=i;
				break;
			}
		}
		for(int i=1;i<=n;i++) {
			if(c[i]>=fircan-1) {
				ans+=fac;
				ans%=MOD;
			}
		}
		cout<<ans<<endl;
		return 0; 
	}
//	if(n<=10) {
		vector<int> num;
		for(int i=1;i<=n;i++) {
			num.push_back(i); 
		}
		int ans=0;
		do {
			int cnt=0;
			for(int i=0;i<num.size();i++) {
				if(cnt>=c[num[i]]||!s[i+1]) {
					cnt++;
					continue;
				}
			}
			if(n-cnt>=m)
				ans++;
		} while(next_permutation(num.begin(),num.end())); 
		cout<<ans%MOD<<endl;
		return 0;
//	}
	//Ultra285K的处理器，直接上1e9我估计都TLE不了几个test
	//在n^2logn或n^3这个复杂度就够了 
	//dp[i][j][k]：第i天用了第j个人录取了k人 
	//考虑转移 
	//dp[i][j][k]=dp[i-1][1~nexceptj]
	//eee先把拼盘写上 
	//怎么感觉dp不行了
	//暴力吧 

	return 0;
}

