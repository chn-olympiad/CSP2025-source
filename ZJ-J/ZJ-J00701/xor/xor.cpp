#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,k,ans;
ll a[500010];
ll b[500010];
bool c[500010];
bool flag,flag1;
bool fun(ll x,ll y) {
	for(ll i=x; i<=y; i++) {
		if(c[i]) return false;
	}
	return true;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cnt=n;
	memset(c,false,sizeof(c));
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) {
			flag=1;
		}
		if(a[i]!=0&&a[i]!=1) {
			flag1=1;
		}
	}
	b[1]=a[1];
	for(ll i=2; i<=n; i++) {
		b[i]=(a[i]^b[i-1]);
	}
	if(!flag) {
		cout<<n/2;
	} else if(!flag1) {
		if(k==1) {
			for(int i=1; i<=n; i++) {
				if((a[i]==1&&a[i+1]==0)||(a[i+1]==1&&a[i]==0)){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}else{
			for(int i=1; i<=n; i++) {
				if((a[i]==1&&a[i+1]==1)){
					ans++;
					i++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			cout<<ans;
		}
	} else {
		for(ll i=1; i<=n&&cnt>=0; i++) {
			for(ll j=1; j+i-1<=n; j++) {
				if(j==1) {
					if(b[i]==k&&fun(1,i)) {
						for(ll k=j; k<=i+j; k++) {
							c[i]=1;
						}
						cnt-=i;
						ans++;
					}
				} else {
					if((b[j-1]^b[i+j-1])==k&&fun(j,i+j-1)) {
						for(ll k=j; k<i+j; k++) {
							c[i]=1;
						}
						cnt-=i;
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
