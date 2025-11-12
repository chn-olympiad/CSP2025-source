#include<bits/stdc++.h>
using namespace std;

int n,m,x=1;
int a[1000];
int q[200][200];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				q[j][i]=a[x];
				x++;
			}
		}else{
			for(int j=1;j<=n;j++){
				q[j][i]=a[x];
				x++;				
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(q[i][j]==r){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
} 













