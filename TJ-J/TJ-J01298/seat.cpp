#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,z,ber;
int cheng[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>cheng[i];
	}
	r=cheng[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(cheng[j]<cheng[j+1]){
				z=cheng[j];
				cheng[j]=cheng[j+1];
				cheng[j+1]=z;
			}
		}
	}
	
	for(int i=0;i<n*m;i++){
		if(cheng[i]==r){
			ber=i+1;
		}
	}
	int h=0;
	int l=0;
	if(ber%n==0){
		l=ber/n;
	}else{
		l=ber/n+1;
	}
	if(l%2==0&&l!=1){
		h=l*n-ber+1;
	}else{
		h=n-(l*n-ber);
	}
	cout<<l<<" "<<h;
	return 0;
}
