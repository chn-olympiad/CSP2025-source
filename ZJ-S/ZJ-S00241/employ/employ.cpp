#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ttl=0,pl[505];
long long ans=1,ans1=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		pl[c[i]]++;
	}
	if(pl[0]+m>n){
		cout << 0;
		return 0;
	}
	for(int i=n-pl[0];i>=n-pl[0]-m+1;i--){
		ans*=i;
		ans%=998244353;
	}for(int i=2;i<=n-m;i++){
		ans1*=i;
		ans1%=998244353;
	}
	cout << (ans1*ans)%998244353;
	return 0;
}
