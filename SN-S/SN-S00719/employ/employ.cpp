#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
typedef long long ll;
int n,m;
ll ans=1;

int main(){
	
	freopen("employ.in","r",stdin);//Òª¸Ä 
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=2;i<=m;i++){//mµÄ½×³Ë 
		ans=(ans*i)%MOD;
	}
	
	cout<<ans<<endl;
	return 0;
} 
/*
3 2
101
1 1 2
*/ 
