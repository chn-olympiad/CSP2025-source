#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
long long n,m,c[N],ans=0;
string s;
long long jie(long long k){
	long long cnt=1;
	for(int i=1;i<=k;i++){
		cnt=(cnt*i)%mod;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=0;
	for(int i=m;i<=n;i++){
		ans=(ans+jie(i))%mod;
	}
	cout<<ans;
	return 0;
}