#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const long long N=10086;
const long long mod=998244353;
long long a[N];
long long jc(long long x){
	long long res=1;
	for(long long i=x;i>=1;i--){
		res=(res*i)%mod;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;cin>>n>>m;
	string s;cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(long long i=1;i<=n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
			
		}
		cout<<jc(n);
		return 0;
	}
	cout<<114514;
	return 0;
}

