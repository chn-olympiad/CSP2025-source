#include<bits/stdc++.h>
using namespace std;
int cmt(int a,int b){
	return b<a;
}
int a[109],b[10][10];
int main(){
	freopen("seat.in",r,stdin);
	freopen("seat.out",w,stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int t=a[0],cnt=0;
	sort(a,a+n*m,cmt);
//	for(int i=0;i<n*m;i++){
//		if(t==a[i]){
//			cnt=i;
//		}
//	}
	for(int j=0;j<m;j++){
		for(int i=0,k=1;i<n;i++,k++){
			if(j%2==0){
				b[i][j]=a[n*j+i];
			}else{
				b[i][j]=a[n*(j+1)-k];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==t){
				cout<<j+1<<" "<<1+1;
			}
		}
		cout<<endl;
	}
	return 0;
}
