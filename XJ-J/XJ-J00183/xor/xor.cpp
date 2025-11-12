#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
int n,k,a[N],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*9 0
0 1 0 1 1 0 1 1 1
*/
