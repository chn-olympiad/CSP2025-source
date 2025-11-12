#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
    int n,m,c,r;
    cin >> n >> m;
    int a[100]={};
    for(int i=0;i<=100;i++){
        cin >> a[i];
	}
	int Rc = a[1];
	int x,y=0;
	for(int i=0;i<=100;i++){
		int m = max(a[i],m);
		int n = min(a[i],n);	
	}
	for(int i=0;i<=100;i++){
		if(a[i]==Rc){
			x = i;
			break;
		}
	}
    y = x / n;
	if(x % n != 0){
		x = x % n; 
	}
	
	
	cout << y << " " << x;
	return 0; 
}
