#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
const ll modd=998244353;
int n,m,c[maxn];
ll ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=m;i<=n;i++){
		ll sum=1,num=1;
		for(int j=n;num<=i;num++,j--){
			sum=sum*j/num;
		}
		ans=(ans%modd+sum%modd);
	}
	cout<<ans;
	return 0;
}
