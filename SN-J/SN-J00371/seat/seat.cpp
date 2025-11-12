#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100009],b[100009];
	int z[400][400];
	int m,n,t=0,ao=0;
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
		if(i==0)ao=a[i];
	}
	int ws=0,mt=0;
	for(int k=0;k<m*n;k++){
		ws=0;
		mt=0;
		for(int i=0;i<m*n;i++){
			if(a[i]>mt){
				mt=a[i];
				ws=i;
			}
		}
		b[k]=mt;
		a[ws]=0;
}
for(int i=0;i<m;i++){
	if((i==0)||(i%2==0)){
	for(int j=0;j<n;j++){
		z[i][j]=b[t];
		++t;
	}
}else{
	for(int j=n-1;j>=0;j--){
		z[i][j]=b[t];
		++t;
	}
}
}

for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	if(z[i][j]==ao){
		cout<<i+1<<' '<<j+1;
		return 0;
	}
}
}
	return 0; 
} 
