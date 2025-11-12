#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,c,cr;
	cin >> n >> m;
	int a[105];
	for(int i=0;i < n *m;i++){
		int b = 0;
		cin >> b;
		a[i] = b;
		}
	if (a[0]== 100){
		cout << 1 << " " << 1;
		return 0;
	}	
	int r = a[0];
	for (int i = 0;i < n*m-1;i++){
		for (int l = 0;l <= i;l++){
			if (a[l] < a[l+1]){
			int h = a[l];
			a[l] = a[l+1];
			a[l+1] = h;
			
		}
		
		}
		
	}
	
	for (int i = 0;i < n*m-1;i++){
		
		if (a[i] == r){
		t = i+1;
	}
	}
	if (t % n==0){
		c = t/n;
	} 
	else {
		c = t/n +1;
	}
	if (c % 2 == 0){
		if (t% m==0) {
			cr = 1;
		}
		else if(t % m==1){
			cr = m;
		}
		else{
			cr = m -(t%m-1);
		}
	}
	else{
		if (t%m==0){
			cr = m;	
		}
		else{
			cr = t%m;
		}
	}
			
	
	
	cout << c << " " << cr;
	return 0;
}
	
	

