#include <bits/stdc++.h> 
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w"stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i <= n*m;i++){
		cin >> a[i];
	}
	int r=a[1],c=0;
	for(int i=1;i < n*m;i++){
		for(int j=i+1;j <= n*m;j++){
			if(a[i] < a[j]){
				c =a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
	for(int i =1;i <= n*m;i++){
		if(a[i] == r){
			c = i;
			break;
		}
	}
	int l=0,h=0;
	if(c/n%2 == 1){
		if(c%n == 0){
			l = c/n;
			h = n;
		}
		else{
			l = c/n+1;
			h = n-c%n+1;
		}
	}
	else if(c/n%2 == 0){
		if(c%n == 0){
			l = c/n;
			h = 1;
		}
		else{
			l = c/n+1;
			h = c%n;
		}
	}
	cout << l << " " << h;
	fclose("seat.in");
	fclose("seat.out");
	return 0;
}
