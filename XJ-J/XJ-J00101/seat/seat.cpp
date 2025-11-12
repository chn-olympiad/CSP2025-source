#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m],b[m*n],p,q;
	for(int i = 0;i < m*n;i++){
		scanf("%d",&b[i]);
		q = b[0];
	}
	for(int i = 0;i < n*m;i++){
		for(int j = 0;j < i;j++){
			if(b[j] > b[i]){
				p = b[i];
				b[i] = b[j];
				b[j] = p;
			}
		}
	}
	int c = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			a[j][i] = b[c];
			c++;
			if(a[j][i] == q){
				printf("%d %d",i+1,j+1);
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
