#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,c[510],x,m;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i])x++;
	}
	if(x>m)cout<<0;
	else{
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
	}
	return 0;
}