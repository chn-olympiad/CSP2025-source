#include<bits/stdc++.h>
using namespace std;
int to[int(1e3+20)][int(1e3+20)],v[int(1e3+20)],n,m,k,Min=int(1<<30);
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
//	printf("\n\n%d %d %d\n\n",n,m,k);
	memset(to,127,sizeof(to));
	for(int i=1;i<=m;i++){
		int w,v,u;scanf("%d%d%d",&u,&v,&w);
		to[u][v]=w;
		to[v][u]=w;
	}
//	printf("\n-1-\n");
	for(int i=1;i<=k;i++){
		int c;scanf("%d",&c);
//		printf("\n-1-\n");
		for(int j=1;j<=n;j++){
			int a;scanf("%d",&a);
			to[n+i][j]=a+c;
			to[j][n+i]=a+c;
//			printf("\n%d=>%d,%d\n",k,i,n);
		}
//	printf("\n-1-\n");
	}
	for(int i=n+1;i<=n+k;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(to[j][i]+to[i][k]<to[j][k]){
					to[j][k]=to[j][i]+to[i][k];
					to[k][j]=to[j][i]+to[i][k];
				}
			}
		}
	}
	int q=i,sum=0;
	for(int i=1;i<=n;i++){
		int num=1;
		for(int j=1;j<=n;j++){
			if(to[q][num]>to[q][j]){
				num=j;
			}
		}
		sum+=to[q][num];
		q=num;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/**
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
