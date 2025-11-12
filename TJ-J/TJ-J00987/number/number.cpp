#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long b,c,d;
	//for(int i=0;i<=1000000;i++){
		cin>>b;
		if(b<10){
			cout<<b;
			return 0;
		}
		//d=b%10;
		//a[d]+=1;
		for(long long y=b;y>=1;y/=10){
			c=y%10;
			a[c]+=1;
			//if(y<10){
				//a[y]+=1;
			//}
		}
	//}
	for(int j=10;j>=0;j--){
		if(a[j]>1){
			for(int x=a[j];x>=1;x--){
				cout<<j;
			}
		}else if(a[j]==1){
			cout<<j;
		}
	
		
		 
		
		
	}
	
	
return 0;	
}
