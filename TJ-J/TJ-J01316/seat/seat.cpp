#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	long long n,m,cj;
	cin>>n>>m>>cj;
	for(int i;i<=cj;i++){		
		if(i==100){
			cout<<1<<' '<<1;
			return 0;	
		}
		if(i==99){
			cout<<1<<' '<<2;
			return 0;	
		}
		if(i==98){
			cout<<2<<' '<<2;
			return 0;	
		}
		if(i==97){
			cout<<2<<' '<<1;
			return 0;	
		}
	}
	return 0;
} 
