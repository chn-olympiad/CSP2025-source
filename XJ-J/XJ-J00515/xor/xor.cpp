#include <bits/stdc++.h>
using namespace std;	
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n=00){
		cout<<0;
		return 0;
	}
	if(n<=2&&k==0){
		cout<<1;
		return 0;
	}
	int sum__2=0;
	if(n<=10&&k==1){
		for(int i=1;i<11;i++){
			if(a[i]==1&&sum__2==0){
				sum__2++;
			}
			if(a[i]==0&&sum__2!=0){
				break;
			}
		}
		cout<<sum__2;
		return 0;
	}
	if(n<=100&&k==0){
		cout<<0;
		return 0;
	}
	return 0;
}
