#include <bits/stdc++.h>
using namespace std;

int m,n;
int c,r;
int a[102];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	int sum = n*m;
	for(int i = 0;i<sum;i++){
		cin>>a[i];
	}
	int fen_r = a[0];
	if(sum == 1){
		cout<<1<<" "<<1;
	}
	int temp = 0; 
	for(int i = 0;i<sum-1;i++){
		for(int j = 0;j<sum-1;j++){
			if(a[j] < a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	int wei_r = 0;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			int wei_i = (i*n)+j;
			if(a[wei_i] == fen_r){
				c = i+1;
				if(i%2 == 1){
					r = n-(j+1)+1;
				}
				else{
					r = j+1;
				}
				cout<<c<<" "<<r;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
