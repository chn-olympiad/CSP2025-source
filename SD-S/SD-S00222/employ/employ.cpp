#include<bits/stdc++.h>
#define debug 0
#define mod 998244353
#define int long long
using namespace std;

int n,m;
bool can[510];
int aa[510];
int c[510];
int a;
int onec;

int pai[510];

bool check() {
	int ans=0;
	int nn=0;
	int now=0;
	for(int i=0; i<n; i++) {


		while(nn>=c[pai[now]]) {
			now++;
			if(now>=n)break;
		}
		if(can[i]) {
			ans++;
		} else {
			nn++;
		}

		now++;
		if(now>=n)break;
	}
	cout<<ans;
	return ans>=m;
}
int ans;
void dfs(int ii) {
	if(ii==n) {
		if(check()) {
			ans++;
		}
		return;
	}

	for(int i=0; i<n; i++) {
		bool fl=1;
		for(int j=0; j<ii; j++) {
			if(i==pai[j]) {
				fl=0;
				//cout<<'!';
			}
		}
		if(fl) {
			pai[ii]=i;
			dfs(ii+1);
		}

	}
}

signed main() {
	if(!debug) {
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	}

	cin>>n>>m;
	string a;
	cin>>a;

	bool sp1=1;

	for(int i=0; i<a.size(); i++) {
		if(a[i]=='1') {
			can[i]=1;
			onec++;
		} else {
			sp1=0;
		}
	}

	int ii=0;

	for(int i=0; i<n; i++) {
		cin>>c[i];
		if(c[i]==0) {
			ii--;
		}
		ii++;
	}

	if(sp1) {
		if(debug)cout<<'a';
		int ans=1;
		for(int i=1; i<=ii; i++) {
			ans*=i;
			ans%=mod;
		}
		for(int i=1; i<=n-ii; i++) {
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}

	if(m==1) {
		if(debug)cout<<'b';
		int ans=1;
		for(int i=1; i<=ii; i++) {
			ans*=i;
			ans%=mod;
		}
		for(int i=1; i<=n-ii; i++) {
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}

	sort(c,c+n);

	aa[0]=!can[0];
	for(int i=1; i<n; i++) {
		aa[i]=aa[i-1]+(!can[i]);
	}
	if(n<=18) {
		dfs(0);
		cout<<ans;
		return 0;
	}

	cout<<0;
	return 0;
}
