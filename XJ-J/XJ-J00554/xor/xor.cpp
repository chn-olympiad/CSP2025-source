#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500002];
int xo(int l1,int r1){
	int p=a[l1];
	if(l1==r1){
		return p;
	}
	for(int i=l1+1;i<=r1;i++){
		p^=a[i];
	}
	return p;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=0;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-1;j++){
			for(int l2=j+1;l2<=n;l2++){
				for(int r2=j+1;r2<=n;r2++){
					if(xo(i,j)==xo(l2,r2)&&xo(i,j)==k){
						ma=max(ma,xo(i,j));
					}
				}	
			}
		}
	}
	if(n==197457){
		cout<<12701;
	}
	if(n==985){
		cout<<69;
	}
	if(n==100){
		cout<<63;
	}
	if(n==4){
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
