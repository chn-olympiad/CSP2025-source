#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[512];
int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m;
	cin >> n >> m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i]==0)cnt++;
	}
	if(cnt>n-m){
		cout<< 0;
	}else{
		int ans=1;
		for(int i=1;i<=n-cnt;i++){
			ans*=i;
			ans%=mod;
		}
		cout << ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
