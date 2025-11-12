//刘腾堃 SN-S00084 西安市经开第三中学 
#include<iostream>
using namespace std;
int main(){
	ferogen("club.in","r",stdin);
	ferogen("club.out","w",stdout);
	int t;
	int sum[4];
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		int a[300000][2];
		cin>> n;
		for(int j=0;j< 3*n;j++){
			int max=0; 
			int b=0;
			for(int k=0;k<3;k++){
				cin>> a[j][0];
				a[j][1]=k+1;
				if(a[j][0] > max){
					max=a[j][0];
					b=j;
				}
			}
			a[b][1]=0;
		}
		for(int j=0;j<3;j++){
			int b[2][2];
			for(int k=0;k<n;k++){
				if(a[j+3*k][1] == 0){
					if(a[j+3*k][0] > b[0][0]){
						if(a[b[0][1]+1][1] == 0){
							a[b[0][1]][1] = a[b[0][1]-1][1]+1;
						}else a[b[0][1]][1] = a[b[0][1]+1][1]-1;
						b[0][0] = a[j+3*k][0];
						b[0][1] = j+3*k;
					}else if(a[j+3*k][0] > b[1][0]){
						if(a[b[1][1]+1][1] == 0){
							a[b[1][1]][1] = a[b[1][1]-1][1]+1;
						}else a[b[1][1]][1] = a[b[1][1]+1][1]-1;
						b[1][0] = a[j+3*k][0];
						b[1][1] = j+3*k;
					}else {
						if(a[j+3*k+1][1] == 0){
							a[j+3*k][1] = a[j+3*k-1][1]+1;
						}else a[j+3*k][1] = a[j+3*k+1][1]-1;
					}
				}
			}
		}
		for(int j=0;j<3*n;j++){
			if (a[j][1] == 0){
				sum[i]+=a[j][0];
			}
		}
	}
	for(int i=0;i<t;i++){
		cout << sum[i] << endl;
	}return 0;
}
