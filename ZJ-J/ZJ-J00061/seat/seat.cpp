#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],R,cc,c=0,rr=0,r=1,o=0,ooo;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-1;j++){
			if(a[j]<a[j+1]){
				ooo=a[j];
				a[j]=a[j+1];
				a[j+1]=ooo;
				
			}
		}
	}
	for(int i=0;i<m;i++){
		c++;
		for(int j=0;j<n;j++){
			
			if(R==a[o]){cc=c;
				rr=r;}
			if(i%2==0){
				r++;
			}else{r--;}
			o++;
		}
		if(i%2==1){
				r++;
			}else{r--;}
		
	}
	cout<<cc<<' '<<rr;
	return 0;
}
