#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const int mod = 998244353;
int n,m;
int s[510],c[510];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int sum = 0;
    for(int i=1;i<=n;i++) {
	char c; cin>>c;
	if(c=='1') s[i] = 1,sum++;
	else s[i] = 0;
    }
    if(sum==n) {
	int ans = 1;
	while(n--) {
	    ans*=(n+1);
	    ans%=mod;
	}
	cout<<ans<<endl;
    }
    else if(m==1) {
	if(sum>0) {
	    int ans = 1;
	    while(n--) {
	        ans*=(n+1);
	        ans%=mod;
	    }
	    cout<<ans<<endl;
	}else cout<<0<<endl;
    } else if(sum==0) cout<<0<<endl;
    else if(m==n) {
	if(sum<n) cout<<0<<endl;
    }
    return 0;
}