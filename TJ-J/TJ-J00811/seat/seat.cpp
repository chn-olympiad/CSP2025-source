#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	int a[101]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	
	sort(a+1,a+(n*m)+1,px);
	
	int c=1;
	int b[11][11]={};
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[c];
				c++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[c];
				c++;
			}
		}
	}
		
		
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==a1){
				cout<<j<<' '<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
