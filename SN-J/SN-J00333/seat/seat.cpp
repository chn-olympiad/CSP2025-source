//SN-J00333 张展翔 临渭区示范学校 
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[101],b[11][11],d=0,e=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-i;j++){
			if(a[i]<a[i+1]){
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	int c=1;
	for(int i=1;i<=m;i++){
		    if(i%2==1){
			   for(int j=1;j<=n;j++){
			   	    b[j][i]=a[c];
			   	    c++;
			   }		
			}
			if(i%2==0){
			   for(int j=n;j>=1;j--){
			   	    b[j][i]=a[c];
			   	    c++;
			   }	
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				d=j;
				e=i;
				break;
			}
		}
	}
	cout<<d<<" "<<e;
	return 0;
}
