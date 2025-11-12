#include<bits/stdc++.h>
using namespace std;
int a[1005][260],b[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=(j+i-1)&&((i+j-1)<=n);j++){
			sum=(sum^b[j]);
		}
		a[i][sum]=1;
	}
	for(int i=n;i>=1;i--){
		for(int j=50;j>=0;j--){
			if(a[i][j]==m){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}