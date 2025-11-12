#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long int n,m,ans=1;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin >> n >> m;
	if(m==n){
		cout << 0;
		return 0;
	} else if(m == 1){
		for(int i = m;i<=n;i++){
			ans*=i;
			ans%=M;
		}
	}
	cout << ans;
	return 0;
}