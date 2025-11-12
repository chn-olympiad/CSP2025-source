#include <bits/stdc++.h>
using namespace std;
bool o(int x,int y){
	return x>=y;
}
int z[121];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 int a,b,c,d=0,e=0;
	 cin>>a>>b;
	 for(int i=0;i<a*b;i++){
	 	cin>>z[i];
	 }
	 c=z[0];
	 sort(z,z+a*b,o);
	 for(int x=0;x<b;x++){
	 	if(x%2==0){
	 		d=0;
		 }
		 else{
		 	d=a-1;
		 }
	 	for(int y=0;y<a;y++){
	 		
	 		if(c==z[e]){
	 			cout<<x+1<<' '<<d+1;
	 			return 0;
		 	}
			if(d<a){
	 			d++;
			}
			else{
			 	d--;
			}
		 	e++;
		 }
	 }
}
