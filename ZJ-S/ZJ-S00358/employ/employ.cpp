#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int s[50000];
int c[50000];
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	 int ans=1;
	 for(int i=n;i>=1;i--){
	 ans=ans*i%mod;
    }
    cout<<ans;
}
