#include<bits/stdc++.h>
using namespace std;
int a,pf,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		if(i==1)a=x;
		else if(x>a)pf++;
	}
	bool flag=true;
	for(int i=1;i<=m;i++){
		if(flag==true){
			for(int j=1;j<=n;j++){
				k++;
				if(k==pf+1){
					printf("%d %d",i,j);
					return 0;
				}
			}
			flag=false;
		}
		else{
			for(int j=n;j>=1;j--){
				k++;
				if(k==pf+1){
					printf("%d %d",i,j);
					return 0;
				}
			}
			flag=true;
		}
	}
	return 0;
}