#include<bits/stdc++.h>
using namespace std;

int main(){
	int a=0,m=0,u=0;
	cin >> a >> m;
	int p = a*m;
	int n[p];
	for(int i = 1;i <= p;i++){
		cin >> n[i];
	}
    int y = n[1];
	for(int j=0;j <= 200;j++){
		for(int i = 1;i <= p-1;i++){
		if(n[i+1] > n[i]){
			u = n[i+1];
			n[i+1] = n[i];
			n[i] = u;
		}
	}
    }
    int w =0;
	for(int i = 1;i <= p;i++){
		if(n[i]=y){
			w = i;
		}
	}
	int ans1;
	if(w %a != 0){
		ans1=1+ w/a;
	}else{
		ans1=w/a;
	}
	int ans2;
	if(ans1 %2 != 0){
		ans2 = w- a*(ans1-1);
	}else{
		ans2 = 1+a - (w- a*(ans1-1)) ;
	}
	cout << ans1 <<" "<< ans2;
	return 0;
}
