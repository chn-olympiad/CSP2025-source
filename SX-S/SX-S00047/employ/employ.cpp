#include<iostream>
#define int long long
using namespace std;
const int N=503,AN=998244353;
int c[N],ans,pas;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n,m;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){

		}
		else{

		}
		if(pas>=m){
			ans++;
			ans%=AN;
		}
	}
	cout<<ans%AN;
	return 0;
}