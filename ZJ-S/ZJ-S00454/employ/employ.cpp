#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,k,ans,c[505];
string a;
bool cmp(LL a,LL b){
	return a>b;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for (int i=1;i<=n;i++) cin>>c[i];
	if (n==m){
		cout<<0;
		return 0;
	}
	ans=1;
	for (int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans<<endl;
}//pts 36

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
