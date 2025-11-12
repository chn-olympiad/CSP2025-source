#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,mod=998244353;
ll n,a[N],b[N],c[N][N],mbz,num;
ll sum=-1;
ll ans;
bool f1=true;
bool cmp(int x,int y) {
	return x>y;
}
ll ksm(int x) {
	if(x==0) return 1;
	else if(x%2==0) return ((ksm(x/2)%mod)*(ksm(x/2)%mod))%mod;
	else if(x%2==1) return ((ksm((x-1)/2)%mod)*(ksm(((x-1)/2)%mod)*2))%mod;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) f1=false;
		b[i]=b[i-1]+a[i];
	}
	if(f1==true) {
		ll x=ksm(n)%mod;
		ll y=(((((n+1)%mod)*(n%mod))%mod/2)%mod+1)%mod;
		cout<<(x-y%mod)%mod<<"\n";
		return 0;
	}
	else if(n==1) {
		cout<<0<<"\n";
		return 0;
	}
	else if(n==2) {
		cout<<0<<"\n";
		return 0;
	}
	else if(n==3) {
		if((a[1]+a[2]+a[3])>(2*(max(a[1],max(a[2],a[3]))))) {
			cout<<1<<"\n";
		}
		else {
			cout<<0<<"\n";
		}
		return 0;
	}
	else if(n==4) {
		int ans=0;
		if(b[n]>2*(max(max(a[1],a[2]),max(a[3],a[4])))) ans++;
		if((a[1]+a[2]+a[3])>(2*(max(a[1],max(a[2],a[3]))))) ans++;
		if((a[1]+a[2]+a[4])>(2*(max(a[1],max(a[2],a[4]))))) ans++;
		if((a[2]+a[3]+a[4])>(2*(max(a[2],max(a[3],a[4]))))) ans++;
		cout<<ans<<"\n";
	}
	else if(n==5) {
		int ans=0;
		if(b[n]>2*(max(max(max(a[1],a[2]),max(a[3],a[4])),a[5]))) ans++;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int k=j+1;k<=n;k++) {
					for(int m=k+1;m<=n;m++) {
						if((a[i]+a[j]+a[k]+a[m])>2*(max(max(a[i],a[j]),max(a[k],a[m])))) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int k=j+1;k<=n;k++) {
					if((a[i]+a[j]+a[k])>(2*(max(a[i],max(a[j],a[k]))))) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	else if(n==6) {
		int ans=0;
		if(b[n]>2*(max(max(max(a[1],a[2]),max(a[3],a[4])),max(a[5],a[6])))) ans++;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int k=j+1;k<=n;k++) {
					for(int m=k+1;m<=n;m++) {
						for(int x=m+1;x<=n;x++) {
							if((a[i]+a[j]+a[k]+a[m]+a[x])>2*(max(max(max(a[i],a[j]),max(a[k],a[m])),a[x]))) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int k=j+1;k<=n;k++) {
					for(int m=k+1;m<=n;m++) {
						if((a[i]+a[j]+a[k]+a[m])>2*(max(max(a[i],a[j]),max(a[k],a[m])))) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				for(int k=j+1;k<=n;k++) {
					if((a[i]+a[j]+a[k])>(2*(max(a[i],max(a[j],a[k]))))) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	else {
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				c[i][j]=max(c[i][j-1],a[j]);
			}
		}
		for(int l=1;l<=n;l++) {
			for(int r=l+2;r<=n;r++) {
				if((b[r]-b[l-1])>(2*c[l][r])) {
					ans++;
				}
			}
		}
		cout<<(ans%mod)<<"\n";
	}
	return 0;
}
