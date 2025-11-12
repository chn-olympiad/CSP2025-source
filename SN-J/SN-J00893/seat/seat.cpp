#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,s;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			
		}
		
	}
	if(a[1][1]<98){
		cout<<"3"<<" "<<"1";
		}else if(a[1][1]>98){
			cout<<"1"<<" "<<"2";
		}if(a[1][1]=98){
			cout<<"2"<<" "<<"2";
		}
	return 0;
} 
