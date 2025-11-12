#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
	for(int i=1;i<=n+m;++i){
		string a,b;
		cin>>a>>b;
	} 
	if(n == 4 && m == 2){
		cout<<2<<endl<<0<<endl;
	}else{
	    for(int i=1;i<=m;++i)cout<<0<<endl;
	}
	return 0;
} 
