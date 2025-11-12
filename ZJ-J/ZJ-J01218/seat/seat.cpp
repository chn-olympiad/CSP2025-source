#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int flag=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(flag==a[(i-1)*n+j]){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(flag==a[(i-1)*n+(n-j+1)]){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}