#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[510],sum,ans=1,k;
string s;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			sum++;
		}else{
			if(a[i]>sum){
				k++;
			}else{
				sum++;
			}
		}
		if(k>=m){
			for(int j=i+1;j<=n;j++){
				ans*=n-sum-i+1;
				ans%=998244353;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}/*
3 2
101
1 1 2
*/