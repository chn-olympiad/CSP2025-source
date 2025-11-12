#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m,k,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}k=a[1];
	sort(a+1,a+n*m+1);
	int c=1,r=1,cnt=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt]==k){
					printf("%d %d",i,j);
					return 0;
				}cnt--;
			}
		}else {
			for(int j=n;j>=1;j--){
				if(a[cnt]==k){
					printf("%d %d",i,j);
					return 0;
				}cnt--;
			}
		}
	}return 0;
}
