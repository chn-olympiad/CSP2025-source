#include<bits/stdc++.h>
using namespace std;

int n,m;
int pos[15][15];
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int now=a[1];
	sort(a+1,a+n*m+1);
	int cnt=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				pos[i][j]=a[cnt];
				if(a[cnt]==now){
					printf("%d %d",j,i);
					return 0;
				}
				cnt--;
			}
		}else{
			for(int i=n;i>=1;i--){
				pos[i][j]=a[cnt];
				if(a[cnt]==now){
					printf("%d %d",j,i);
					return 0;
				}
				cnt--;
			}
		}
	}
	return 0;
}
/*
2 2
98 99 100 97 
*/
