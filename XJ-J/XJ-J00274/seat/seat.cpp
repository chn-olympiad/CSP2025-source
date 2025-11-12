#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	int r,n,m,x,flag=0;
 	int ans[2];
 	bool flagq=false,flagh=false;
 	cin>>n>>m>>r;
	for(int i=1;i<=m;i++){//列 
		if(i%2==1){//奇数列正序 
			for(int j=1;j<n;j++){	//行 
				cin>>x;
				if(flag==0){
					if(r<x){
						flagq=true;
					}
				}
				else if(flag==1){
					if(r>x){
						flagh=true;
					}
				}
				if(flagq){
					flag++;
					ans[0]=i;
					ans[1]=j;
				}
				if(flagh){
					flag++;
					ans[0]=i;
					ans[1]=j;
				}
				if(flag==2){
					cout<<i<<' '<<j+1;
					break;
				}
				else{
					flagq=false;
					flagh=false;
					flag=0;
				}
			}
		}
		else{//偶数列倒叙 
			for(int j=n;j>1;j--){	//行 
				cin>>x;
				if(flag==0){
					if(r<x){
						flagq=true;
					}
				}
				else if(flag==1){
					if(r>x){
						flagh=true;
					}
				}
				if(flagq){
					flag++;
					ans[0]=i;
					ans[1]=j;
				}
				if(flagh){
					flag++;
					ans[0]=i;
					ans[1]=j;
				}
				if(flag==2){
					cout<<i<<' '<<j-1;
					break;
				}
				else{
					flagq=false;
					flagh=false;
					flag=0;
				}
		}
	}
}
	cout<<ans[0]<<' '<<ans[1]-1;
	return 0;
} 
