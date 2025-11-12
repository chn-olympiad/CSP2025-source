#include<bits/stdc++.h>
using namespace std;
int a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++){
		scanf("%d",&a[i]);
	}
	int g = a[1];
	sort(a+1,a+n*m+1);
	int num;
	for(int i = 1;i <= n*m;i++){
		if(a[i] == g){
			num = n*m-i+1;
		}
	}
	int h,l;
	int y = num%(2*n);
	if(y>n){
		if(y==0){
			h = 1;
		}else{
			h = y-n+1;
		}
	}else{
		if(y==0){
			h = 1;
		}else h = y;
	}
	
	int x = num%n;
	if(num%n!=0){
		l = num/n+1;
	}else{
		l = num/n;
	}
	
	cout << l << " " << h;
	return 0;
}
