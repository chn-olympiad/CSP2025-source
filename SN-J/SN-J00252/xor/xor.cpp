#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],cnt=0;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(m=2){
		cout<<cnt;
	}else{
		cout<<n-m;
	}
	return 0;
}
