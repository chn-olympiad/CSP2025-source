#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=500,mod=998244353;
int n,m;
string s;
int a[N],c[N];
int anss;
int cntt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cntt+=c[i]==0;
		a[i]=i;
	}
	bool f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			f=0;
			break;
		}
	}
//	if(f){
//		if(n-cntt<m){
//			cout<<0;
//		}else{
//			anss=1;
//			for(int i=1;i<=n;i++){
//				anss*=i%mod;	
//				anss%=mod;
//			}
//			cout<<anss;
//		}
//		return 0;
//	}
	if(m==n){
		if(f && cntt==0){
			anss=1;
			for(int i=1;i<=n;i++){
				anss*=i%mod;	
				anss%=mod;
			}
			cout<<anss;
		}else{
			cout<<0; 
		}
		return 0;
	}
	do{
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
			if(s[i-1]=='1'){
				ans++;
			}else{
				cnt++;
			}
		} 
		if(ans>=m){
			anss++;
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<anss;
	return 0;
}