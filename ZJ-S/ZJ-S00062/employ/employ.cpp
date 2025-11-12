#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,mod=998244353;
int n,m,a[N],p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;++i) cin>>a[i],p[i]=i;
	
	long long ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(cnt>=a[p[i]]) cnt++;
			else cnt+=(s[i-1]=='0');
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans%mod;
	return 0;
}
/*
3 2
101
1 1 2

*/
