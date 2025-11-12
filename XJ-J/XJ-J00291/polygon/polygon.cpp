#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod=998244353;
ll a[5005],n,ans=0,sum=0,maxm=0,chosen=0;
bool hj=1;
void bfs(ll x){
	if(x==n+1){
		if(chosen<3) return;
		else if(maxm*2>=sum) return;
		ans++;
		return;
	}
	bfs(x+1);
	chosen++;
	sum+=a[x];
	int c=maxm;
	maxm=max(maxm,a[x]);
	bfs(x+1);
	chosen--;
	sum-=a[x];
	maxm=c;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) hj=0;
	}
	if(n<=3){
		if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2]) ans++;
		cout<<ans;
		return 0;
	}
	if(n<=20){
		bfs(1);
		cout<<ans;
		return 0;
	}
	/*
	if(hj==0){
		int mul=2;
		for(ll i=3;i<=n;i++){
			int nans=1;
			mul=mul*i%mod;
			for(ll j=n;j>=n-i+1;j--){
				nans=
			}
		}
	}
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
