#include <bits/stdc++.h>
using namespace std;
int m,n,a[10100],num,cnt; 
bool cmp(const int &A,const int &B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==cnt){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+(n-j+1)]==cnt){
					printf("%d %d",i,j);
					return 0;
				}
			}			
		}
	}
	return 0;
}
