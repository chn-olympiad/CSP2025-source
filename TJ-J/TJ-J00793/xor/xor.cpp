#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	else if(k==1){
		cout<<cnt;
	}
	return 0;
}
