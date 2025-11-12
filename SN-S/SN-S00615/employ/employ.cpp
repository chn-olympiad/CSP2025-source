#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=1e4+10;
const int modd=998244353;
int n,m;	
string a;
int c[maxn];
int qwq(int x){
	int ans=1;
	for(int i=2;i<=x;i++){
		ans*=i;
		ans%=modd;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(int i=1;i<=n;i++)cin >> c[i];
	cout << qwq(n)%modd/(qwq(m)*qwq(n-m))%modd << endl;
	return 0;
}
