#include <bits/stdc++.h>
using namespace std;
int c[10000];
int p2(int x) {
	if (x==0)return 1;
	if (x==1)return 2;
	long long ans=0;
	long long tmp=p2(x/2);
	ans = (tmp*tmp)%998244353;
	if (x%2==1) ans=(ans*2)%998244353;
	cout<<"DEBUG"<<x<<" "<<tmp<<'\n';
	return ans;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int tmp=0;
	for(int i=0; i<n; i++) {
		cin>>c[i];
	}
	for(int i=0; i<n; i++) {
		if(s[i]=='1')tmp++;
	}
	if(tmp<k) {
		cout<<0<<'\n';
		return 0;
	}
	if(tmp==n) {
		cout<<p2(n)<<'\n';
		return 0;
	}
	return 0;
}