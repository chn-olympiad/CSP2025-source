#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10, Mod=998244353;
int n;
int a[N];
long long ans;
long long t[N];

bool check(int x) {
	int tmp=n, mx=0, sum=0, cnt=0;
	while(x) {
		int t=x&1;
		x>>=1;
		if(t) {
			cnt++;
			sum+=a[tmp];
			mx=max(mx,a[tmp]);
		}
		tmp--;
	}
	if(cnt<3) return 0;
	if(sum>2*mx) return 1;
	return 0;
}

void inti() {
	t[0]=1;
	for(int i=1; i<=n; i++) {
		t[i]=(t[i-1]*i)%Mod;
	}
}

long long pow(long long a,long long b,long long mod) {
	long long res=1;
	while(b) {
		if(b&1) {
			res=(res*a)%Mod;
		}
		a=(a*a)%Mod;
		b>>=1;
	}
	return res;
}

long long C(int x,int y) {
	long long a=(t[y]*t[x-y])%Mod;
	return (t[x]*pow(a,Mod-2,Mod))%Mod;
}

int main() {
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	inti();
	int mx=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx<=1) {
		for(int i=n; i>=3; i--) {
			ans=(ans+C(n,i))%Mod;
		}
	} else {
		for(int i=1; i<(1<<n); i++) {
			if(check(i)) {
				ans++;
			}
		}
	}

	cout<<ans%Mod;
	return 0;
}
