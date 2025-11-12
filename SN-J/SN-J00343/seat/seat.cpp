#include<bits/stdc++.h>
using namespace std;

freopen("D:\SN-J00343\seat\seat.in","r",stdin);
freopen("D:\SN-J00343\seat\seat.out","w",stdout);

int n,m,c,x,y,d;
bool flag;

int main(){
	cin >> n,m;
	int a[n][m],b[n*m];
	for (int i=0;i<n*m;i++){
		cin >> b[i];
	}
	d = b[0];
	
	while (flag == false){
		flag = false;
		for (int i=1;i<n*m;i++){
			if (b[i-1]<b[i]){
				c = b[i-1];
				b[i-1] = b[i];
				b[i] = c;
				flag = true;
			}
		}
	}
	
	for (int i=1;i<=n*m;i++){
		if (b[i-1] == d){
			y = i/4+1;
			if (y%2 != 0){
				x = i%4;
			}else{
				x = 4-i%4+1;
			}
		}
	}
	
	printf("%d %d",x,y);
	
	return 0;
}


