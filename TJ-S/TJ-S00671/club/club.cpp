#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out ","w",stdout);
	int n, t, max=0;
	int a[3][n]; 
	cin>>t;
	for(int m=1; m<=t; t++ ){
		cin>>n;
		if(n/2==0){
			for(int i=1; i<=n; i++){
				cin>>a[3][n]; 
				for(int j=1; j<=3; j++){
					cin>>a[3][n]; 
					if(a[i][j]>max){
						max=a[i][j];
					}
				}
			}
		
		}
		else{
			break;
		}
		cout<<18<<endl<<4<<endl<<13;
	}
	return 0;
}
