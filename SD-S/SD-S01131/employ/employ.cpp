//
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int n,m,c[505],dp[262150][20],tot,a[505],b[505],ans;
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s+1;
	rep(i,1,n)
		cin>>c[i];
	if(m==n){
		sort(c+1,c+n+1);
		rep(i,1,n)
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		if(!c[1]){
			cout<<0;
			return 0;
		}
		int fac=1;
		rep(i,1,n)
			(fac*=i)%=998244353;
		cout<<fac;
		return 0; 
	} 
	rep(i,1,n)
		if(s[i]=='1')
			a[++tot]=i;
	rep(i,1,tot)
		rep(j,1,n)
			if(c[j]<a[i])
				b[i]++;
	if(m==1){//先考虑s_i为1的情况，此时有i-1个人失败了，所以c_{p_i}必须大于i-1 
		//不是 这为啥不对啊？？？？？ 
		//对了 我躺了 
		int fac1=1,fac2=1,res=1;
		rep(i,1,tot)
			(res*=b[i]-i+1)%=998244353;
		rep(i,1,n-tot)
			(fac1*=i)%=998244353;
		rep(i,1,n)
			(fac2*=i)%=998244353;
		cout<<(fac2+998244353-fac1*res%998244353)%998244353;
		return 0;
	}
	dp[0][0]=1;
	rop(i,0,(1<<n)-1){
		rep(j,0,__builtin_popcount(i))
			rep(k,1,n)
				if(!((i>>k-1)&1)){
					if(c[k]<=__builtin_popcount(i)-j||s[__builtin_popcount(i)+1]==48)
						(dp[i|(1<<k-1)][j]+=dp[i][j])%=998244353;
					else
						(dp[i|(1<<k-1)][j+1]+=dp[i][j])%=998244353;
				}
	}
	rep(i,m,n)
		(ans+=dp[(1<<n)-1][i])%=998244353;
	cout<<ans;
	return 0;
}
/*
36
*/

