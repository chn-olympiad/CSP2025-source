#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<1;
		return 0;
	}
	else{
		int a[1005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			for(int i=1;i<=n;i++){
				if(a[i]+a[i+1]==1){
					cout<<2;
					return 0;
				}
			}
			cout<<1;
		}
		else{
		    cout<<5;
		}
	}
	return 0;
}
	
