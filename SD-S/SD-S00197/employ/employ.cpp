#include <bits/stdc++.h>
using namespace std;
const int N=507;
long long n,m,ans=1;
string a;
long long b[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	} 
	int tmp=0;
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

