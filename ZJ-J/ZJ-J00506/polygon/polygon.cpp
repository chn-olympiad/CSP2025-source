//by snakeMC
//now:PAC  ~40pts  TE PAN ~24pts
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
bool cmp(long long a,long long b){
	return a>b;
}
long long cnt=0;
long long n,a[5005];
bool can(vector<long long> v,long long l,long long sum){
	return l>=3&&sum>a[v[0]]*2;
}
long long quick_pow_mod(long long a,long long b){//a ^ b
	long long t=a;
	long long ans=1;
	while(b>0){
		if(!b&1){
			t=t*t%mod;
		}else{
			ans=ans*t%mod;
			t=t*t%mod;
		}
		b>>=1;
	}
	return ans;
}
void dfs(long long k,vector<long long> v,long long l,long long sum){//is improving
	if(k>=n){
		if(can(v,l,sum))cnt=(cnt+1)%mod;
	}else{
		if(can(v,l,sum)){
			cnt=(cnt+quick_pow_mod(2,n-k))%mod;
			return;
		}else{
			dfs(k+1,v,l,sum);
			v.push_back(k);
			dfs(k+1,v,l+1,sum+a[k]);
		}
	}
	return;
}
vector<long long> v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool tp=true;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)tp=false;
	}
	if(tp){
		cout<<quick_pow_mod(2,n-2);
		return 0;
	}
	sort(a,a+n,cmp);
	dfs(0,v,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

