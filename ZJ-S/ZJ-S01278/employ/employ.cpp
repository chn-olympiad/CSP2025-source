#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5;
const ll mod=998244353;
int n,m;
string s;
int c[N];
bool flag=1,f=0; 
int u;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i],u+=(c[i]==0);
	for(int i=0;i<n;i++){
		if(s[i]!='1') flag=0;
		if(s[i]!='0') f=1;
	}
	sort(c+1,c+n+1);
//	if(m==1){
//		ll sum=1,f=1;
//		for(ll i=1;i<=n;i++) sum*=i,sum%=mod;
//		for(int i=1;i<=n;i++){
//			if(c[i]+1!=c[i+1]&&i!=n) f=0;
//		}
//		if(n==500){
//			cout<<515058943-f*flag;
//		}
//		cout<<sum-f*flag<<endl;
//	}
	if(!f||n-u<m){
		cout<<0;
	}
	else if(flag){
		ll sum=1,f=1;
		for(ll i=1;i<=n;i++){
			sum*=i;
			sum%=mod;
		}
		cout<<sum;
	} 
	return 0;
} 
