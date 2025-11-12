#include<bits/stdc++.h>
using namespace std;
struct kkksc03{
	int s,b;
}nu[110],se[15][15];
bool cmp(kkksc03 a,kkksc03 b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&nu[i].s);
		if(i==0)nu[i].b=1;
		else nu[i].b=0;
	}
	sort(nu,nu+n*m,cmp);
	int i=0,j=0,k=0,f=0; 
		if(!f&&j!=n-1)j++;
	while(j!=n-1&&k!=m-1){
		if(f&&j!=0)j--;
		se[j][k]=nu[i];
		i++;
		if(j==n-1){k++;f=1;}
		if(j==0&&k!=0){k++;f=0;}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(se[i][j].b)printf("%d %d",i,j); 
		}
	}
	return 0;
}
