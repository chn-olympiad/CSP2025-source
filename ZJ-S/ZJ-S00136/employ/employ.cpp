#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[5000];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	long long cnt=0,t=0;
	for(int i=0; i<n; i++) {
		cin>>c[i];
		if(c[i]==1) t++;
	}
	if(m>t) {
		cout<<0;
		return 0;
	}
	sort(c,c+n);
	if(n==1&&s[0]==m) {
		cout<<1;
		return 0;
	}
	if(n==1&&s[0]!=m) {
		cout<<0;
	}
	if(n==2) {
		if(t==m) {
			cout<<2;
			return 0;
		}
	} else {
		if(n==3) {
			if(t==m) {
				cout<<3;
				return 0;
			}else{
				if(t>m){
					cout<<0;
					return 0;
				}
			}
		}
		int out=0;
		for(int i=0; i<n; i++) {
			while(c[i]<=out) {
				i++;
			}
			if(s[i]==0) out++;
			else cnt++;

		}
		cout<<cnt%998244353;
	}
	return 0;
}
