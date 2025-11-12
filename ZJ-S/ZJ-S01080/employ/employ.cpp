#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,cnt1,cnt2,ans1,ans2;
int a(int x,int y){
	int t=x,sum=1;
	for(int i=x;i<=y;i++){
		sum*=i;
		sum%=mod;
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=1;i<=n;i++) ans1=(ans1+a(1,i))%mod;
	cout<<ans1%mod;
}