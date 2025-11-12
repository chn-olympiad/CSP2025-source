#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int c[510],p[510];
char s[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool f=1; 
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
		p[i]=i;
	}
//	if(f){
//		int num=0;
//		for(int i=1;i<=n;i++){
//			if(c[i]==0)num++;
//		}
//		if(n-num<m){
//			cout<<0<<'\n';
//			return 0;
//		}
//		int ans=1;
//		for(int i=2;i<=n-num;i++){
//			ans=ans*i;
//			ans=ans%MOD;
//		}
//		cout<<ans<<'\n';
//		return 0;
//	}
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=cnt||s[i]=='0'){
				cnt++;
			}
		}
		ans+=(n-cnt>=m);
		ans=ans%MOD;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
