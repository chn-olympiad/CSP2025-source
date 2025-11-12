#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int a[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
	}
	else{
		long long ans=1,cs=1;
		for(int i=1;i<(m-n+1);i++){
			cs*=i;
			cs%=MOD;
		}
		for(int i=m;i>=m-n+1;i--){
			ans*=i;
			ans%=MOD;
		}
		ans=((ans+MOD)/cs)%MOD;
		cout<<ans;
	}
	return 0;
}