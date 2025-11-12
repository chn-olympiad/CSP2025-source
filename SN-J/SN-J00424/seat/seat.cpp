#include <iostream>
using namespace std;

int main(){
	int x,y;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>y>>x;
	int c,abc = x*y;
	int a[abc];
	cin>>c;
	int r=1;
	for(int i=1;i<x*y;i++){
		cin>>a[i];
		if(a[i]>c){
			r++;
		}
	}
	if(r/y==0&&r<y) cout<<1<<" ";
	else cout<<(r/y)<<" ";
	
	if((r/y)%x==2){
		if(r%y==0) cout<<1;
		else cout<<x-r%y;	
	}else{
		if(r%y==0) cout<<y;
		else cout<<r%y;	
	}

	
	
	
/*	for(int i=0;i<=abc;i++){
		if(i==0){
			cin>>a[0];
		}else{
			
		}
	}
	*/
	return 0;
}
