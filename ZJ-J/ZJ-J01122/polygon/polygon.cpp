#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,mod=998244353;

int n,a[N];

int fastpow(int a,int b){
	if(b==0)return 1;
	int rt=1;
	while(b){
		if(b&1){
			rt*=a,rt%=mod;
		}
		b>>=1,a=a*a,a%=mod;
	}
	return rt;
}

bool check(int x){
	int mx=-2e9,s=0,cnt=0;
	for(int i=1;i<=n;i++,x>>=1){
		if(x&1){
			s+=a[i],cnt++;
			mx=max(mx,a[i]);
		}
	}
	if(cnt<3)return false;
	if(s<=2*mx)return false;
	return true;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=false;
	}
	if(flag){
		if(n<3)cout<<0;
		else cout<<((fastpow(2,n)-n-(n*(n-1))/2-1)%mod+mod)%mod;
		return 0;
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		ans+=check(i);
	}
	cout<<ans<<'\n';
	return 0;
}

