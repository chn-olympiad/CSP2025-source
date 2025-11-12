#include <bits/stdc++.h>
using namespace std;
int const N=1e5+7,MOD=998244353;
int n,m,c[N],nj=1,mj=1,nmj=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		nj*=i;
	}
	for(int i=1;i<=m;i++){
		mj*=i;
	}
	int pl=nj/mj;
	pl/=MOD;
	cout<<pl;
	return 0;
}
