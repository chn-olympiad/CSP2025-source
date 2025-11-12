#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
    int n,m,ans=1;
    string s;
    cin>>n>>m>>s;
    int k=n;
    for(int i=1;i<=n;i++){
    	int a;
    	cin>>a;
    	if(!a)k--;
	}
    for(int i=1;i<=k;i++){
    	ans*=i;
    	ans%=998244353;
	}cout<<ans;
	return 0;
} 
