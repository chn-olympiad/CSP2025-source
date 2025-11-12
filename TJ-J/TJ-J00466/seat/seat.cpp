#include<cstdio>
int a[100],b[100],c[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int t=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=1,k=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[i][j]=a[k++];
			}
		}else{
			for(int j=n;j>=1;j--){
				c[i][j]=a[k++];
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==t){
				printf("%d %d",i,j);
			}
		}
	}
	return 0;
}
