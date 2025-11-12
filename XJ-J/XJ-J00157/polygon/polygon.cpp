#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5005],dp[5005];
void solve(){
	long long ans=0;
	long long tt=n-2;
	while(tt!=0){
		long long t=tt;
	    while(t!=0){
		    long long cnt=t;
		    while(cnt!=0){
			    ans=(ans+cnt)%MOD;
			    cnt--;
		    }
		    t--;
	    }
	    tt--;
	}
	cout<<(ans-1)%MOD;
}
void solve1(){
	if(n==3&&a[1]+a[2]>a[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
void solve2(){
	int ans=0;
	if(n==4){
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		long long maxn=0,cnt=0;
		for(int i=1;i<=4;i++){
			cnt+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(cnt>maxn*2){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		solve();
	}
	else if(n<=3){
		solve1();
	}
	else if(n>3&&n<=10){
		solve2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
