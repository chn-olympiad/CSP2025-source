#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int n,m,mf,mp=1;
	cin>>n>>m;
	int a(1000005);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			mp++;
		}
		if(mp<n){
			cout<<1<<" "<<mp;
		}else{
			cout<<mp/n+1<<" "<<mp%n;
		}
	}
	return 0; 
}
