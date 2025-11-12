#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	if(k==0){
		if(n<=2){
			if(n==1)cout<<0;
			else{
				if(a[1]!=a[2])cout<<0;
				else cout<<1;
			}
			return 0;
		}
	}
	return 0;
}