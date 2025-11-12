#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int p=a[1];
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m-1;i++){
			if(a[i]<a[i+1]){
				int h=a[i];
				a[i]=a[i+1];
				a[i+1]=h;
			}
		}
	}
	//for(int i=1;i<=n*m;i++){
	//	printf("%d ",a[i]);
	//}
	int t[n][m];
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				t[i][j]=a[i+(j-1)*m];
			}
		}else{
			for(int i=n;i>=1;i--){
				t[i][j]=a[j*m-i+1];
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[i][j]==p){
				//printf("%d",p);
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	
}
//for(int i=j*m-3;i<=j*m;i++){
//	t[i][j]=a[i];
//}
//for(int i=1+(j-i)*m;i<=j*m;i++){
//	t[i][j]=a[i];
//}








