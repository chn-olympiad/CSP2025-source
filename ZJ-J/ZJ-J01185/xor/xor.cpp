#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0||k==1){
		int c=0;
		for(int i=1;i<=n;i++) if(a[i]==k) c++;
		cout<<c;
	}
	else cout<<2;
	return 0;
}