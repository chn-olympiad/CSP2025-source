#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long long m,n;
	cin >>m >>n;int s,a[10001],x=1,y=1;string r;
	cin >> r >>s;
	for (int i = 0;i<=10000;i++){
		a[i] = r[i];
		if(a[i]<r[i]){
			y+=1;
			if(y==m){
				x+=1;
				y-=2;
			}
			else if(y==1)x+=1;
		}
	}
	cout << x <<" "<< y;
	return 0;
	fclose(stdout);
} 
