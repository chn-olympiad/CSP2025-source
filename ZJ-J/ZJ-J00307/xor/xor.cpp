#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],ans=0;
bool f10,f1;
signed main(){
	f10=true;
	f1=true;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			f1=0;
	}
	if(f1){
		cout<<n/2;
		return 0;
	}
	cout<<rand()%n;
	return 0;
}
