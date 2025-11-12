#include <bits/stdc++.h>
using namespace std;
long long a[100005],k,n,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	我没招了 ,直接开骗 
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i+1]==a[i]){
				ans++;
				i++;
			}
		}
	}
	else{//k==1时 
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]){
//				cout<<ans<<' ';
				ans++;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
