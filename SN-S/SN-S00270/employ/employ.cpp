//强立琨 SN-S00270 交大附中浐灞右岸学校
#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans,cnt;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
	} 
	for(int i=0;i<=n-m;i++){
		cnt=1;
		for(int j=n;j>=n-i-1;j--){
			cnt*=j;
		}
		ans+=cnt;
	}
	cout<<ans%998244353;
	return 0;
} 
