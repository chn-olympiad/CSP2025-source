#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000],a1,sum;
int nm[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	a1=a[1];
	sort(a+1,a+n*m+1);
	sum=n*m;
	int i=1;
	while(i<=n){
		for(int j=1;j<=m;j++){
			if(a1==a[sum]){
				printf("%d %d",i,j);
				return 0;
			}
			nm[i][j]=a[sum];
			sum--;
		}
		i++;
		for(int j=m;j>=1;j--){
			if(a1==a[sum]){
				printf("%d %d",i,j);
				return 0;
			}
			nm[i][j]=a[sum];
			sum--;
		}
		i++;
	}
	return 0;
}
