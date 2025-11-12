#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,pm=1;
	cin >> n >> m;
	int num[n*m];
	for(int i=0;i<n*m;i++){
		cin >> num[i];
	}
	int r=num[0];
	for(int i=0;i<n*m;i++){
		if(num[i]>r){
			pm++;
		}
	}
	
	int x,y;
	if(pm%n!=0){
		y=pm%n;
	}
	else{
		y=n;
	}

	if(pm%n==0){
		x=pm/n;
	}
	else{
		x=pm/n+1;
	}
	
	if(x%2==0){
		y=abs(y-n-1);
	}
	cout << x << " " << y <<endl;
	return 0;
} 
