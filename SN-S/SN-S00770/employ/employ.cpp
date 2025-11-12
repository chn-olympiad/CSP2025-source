//韩骁-SN-S00770-西安高新第一中学南校区
#include<iostream>
using namespace std;
long long int n,m,ans=1;
long long int man[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>man[i];
	for(int i=0;i<m;i++){
		ans*=(n-i);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

