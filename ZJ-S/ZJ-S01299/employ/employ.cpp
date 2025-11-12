#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=507,mod=998244353;
int n,m,c[N],p[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;string s;cin>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];p[i]=i;
	}
	if(n<=10){
		int ans=0;
		do{
			int cnt=0; 
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||cnt>=c[p[i]])cnt++;
			}
			if(n-cnt>=m){
				ans++;ans%=mod;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
	else if(m==1){
		int cnt[2]={0};
		for(int i=1;i<=n;i++){
			cnt[s[i]-'0']++;
		} 
		if(cnt[1]==0){
			cout<<0;
		}
		else{
			int f=1;
			for(int i=1;i<=n-1;i++){
				f=f*i%mod;
			}
			cout<<cnt[1]*f%mod;
		}
		return 0;
	}
	else if(m==n){
		bool fl=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				fl=1;
			}
		}
		if(fl){
			cout<<0;
		}
		else{
			int f=1;
			for(int i=1;i<=n;i++){
				f=f*i%mod;
			} 
			cout<<f;	
		}
		return 0;
	}
	int f=1;
	for(int i=1;i<=n;i++){
		f=f*i%mod;
	} 
	cout<<f;
	return 0;
}
/*
3 2
101
1 1 2


*/

