#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	long long n,k,x=0,y=-1,z=0;
	int a[2][110011];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[0][i];
		a[1][i]=0;
	}for(int i=0;i<n;i++){
		if(a[0][i]==k){
			x++;
			a[1][i]=1;
		}
//		for(int j=i;j<n;j++){
//			y=a[j]^a[j+1];
//			if(y=k){
//				i=j+2;
//				x++;
//				break;
//			}
//		}y=-1;
	}
	for(int i=0;i<n;i++){
		if(a[1][i]==1){
			continue;
		}else{
			if(a[1][i+1]==0){
				y=a[0][i]^a[0][i+1];
				if(y=k){
					i+=2;
					z++;
					y=-1;
				}
			}else{
				y=-1;
				continue;
			}
			
		}
//		for(int j=i;j<n;j++){
//			if(a[1][j]==1){
//				break;
//			}else{
//				y=a[0][j]^a[0][j+1];
//				if(y=k){
//					i=j+2;
//					x++;
//					break;
//				}
//			}	
//		}y=-1;
	}
	cout<<x+z;
	return 0;
}
