 #include <cstdio>
 int a[11][11];
 int b[101];
 int main(){
 	freopen("seat.in","r",stdin);
 	//freopen("seat.out","w",stdout);
 	int n,m;
 	scanf("%d%d",&n,&m);
 	int xr;
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if (i==1){
			xr=b[1];
		}
		for(int j=1;j<=i;i++){
			int t=b[i];
			b[i]=b[j];
			b[j]=t;
		}
	}
	int nh,mh,bl=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[bl];
			bl++;
			if (a[i][j]==xr){
				mh=i;
				nh=j;
				break;
			}
		}	
	}
	printf("%d %d\n",mh,nh);
 	return 0;
 }
