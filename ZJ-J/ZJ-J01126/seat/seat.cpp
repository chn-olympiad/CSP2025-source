#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],x,b[15][15];

bool cmp(int c,int d){
	return c>d;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++)
		scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++)
				b[i][j]=a[(j-1)*n+i];
		}else{
			for(int i=n;i;i--)
				b[i][j]=a[j*n-i+1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==x){
				printf("%d %d\n",j,i);
				return 0;
			}
	return 0;
}
