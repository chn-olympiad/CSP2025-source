#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r" , stdin);
	freopen("seat.out","w" , stdout);

	int n, m, a[200], l=0, h=0;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=0,my=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j] < a[j+1]){
				o = a[j];
				a[j] = a[j+1];
				a[j+1] = o;
			}
		}
	}
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==my){
			o = i;
		}
	}
	
	l = o/n+1;
	if(l%2 == 1){
		h = +1;
	}else{
		h = m-o%n;
	}
	
	cout<<l<<" "<<h;
	
	return 0;
} 
