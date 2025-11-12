#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	cin>>a;
	strint a; 
	int n;
	for (int i=0;i<=n-1;i++){
		cin>>a;
	    strint a; 
		if(a.length(i)<a.length(i-1)){
			int t;
			t=a.length(i);
			a.length(i)=a.length(i-1);
			a.length(i-1)=t;
			cout<<a.length;
		}
	}
	
	return 0;
} 
