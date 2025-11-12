//SN-J00199  吴禹泽  陕西延安中学
#include<iostream>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 998244353;
int n, a[5005], ans, maxa = -1;

/*inline void sp(){
	for(int i=1; i<=n; i++){
		int 
	}
}*/

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	fastio;
	
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxa = max(maxa, a[i]);
	}
	
	if(n==3) {
		if(a[1] + a[2] + a[3] > 2 * maxa) cout<<1;
		else cout<<0;
	}
	cout<<0;
	
//	if(maxa == 1){
//		sp();
//		return 0;
//	}
	return 0;
}
