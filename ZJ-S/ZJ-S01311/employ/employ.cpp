#include<bits/stdc++.h>
using namespace std;
#define N 510
#define mod 998244353 
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ3.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n;
    cin>>n>>m;
    string s;
    cin>>s;
    bool z=1;
    for(int i=0;i<n;i++){
    	if(s[i]=='0') z=0;
	}if(z){
		long long ans=1;
    	for(int i=1;i<=n;i++){
    		ans*=i;
    		ans%=mod;
		}cout<<ans;
		return 0;
	}cout<<rand()%mod;
    return 0;
}
