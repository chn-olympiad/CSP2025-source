#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],maxn=0,rans;
long long A(long long x,long long m){
	long long ans=1;
	for(long long i=m;i>=m-x+1;i--){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
void solve1(){
	if(n<=2){
		cout<<0;
		return;
	}
	if(n==3){
		if(a[1]>=a[2]&a[1]>=a[3]){
			if(a[1]>=a[2]+a[3]){
				cout<<0;
				return;
			}
			else{
				cout<<1;
				return;
			}
		}
		else if(a[2]>=a[1]&a[2]>=a[3]){
			if(a[2]>=a[1]+a[3]){
				cout<<0;
				return;
			}
			else{
				cout<<1;
				return;
			}
		}
		else if(a[3]>=a[1]&a[3]>=a[2]){
			if(a[3]>=a[1]+a[3]){
				cout<<0;
				return;
			}
			else{
				cout<<1;
				return;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		solve1();
		return 0;
	}
	else if(maxn<=1){
		for(int i=3;i<=n;i++){
			rans+=A(i,n)/A(i,i);
			rans%=mod;
		}
		cout<<rans;
		return 0;
	}
}

