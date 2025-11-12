#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int maion(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int marks[105];
	int r=0;
	for(int i=1;i<=n*m;i++){
		cin>>marks[i];
		r=marks[1];
	}
	sor(marks,marks+n*m,cmp);
	int seat[15][15];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2!=0){
				seat[i++][j];
				
			}else{
				if(j%2==0){
					seat[i][j++];
				}
			}
		}
	}
	return 0;
}
