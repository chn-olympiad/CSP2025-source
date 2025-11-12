#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,tot=1;
int a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&m,&n,&a);
	for(int i=2;i<=n*m;++i){
		scanf("%d",&b);
		if(b>a)++tot;
	}
	int i=1,j=1;
	for(int x=1;x<tot;++x){
		if(i&1){
			++j;
			if(j>m){
				++i;
				j=m;
			}
		}else{
			--j;
			if(j<1){
				++i;
				j=1;
			}
		}
	}
	printf("%d %d",i,j);
	return 0;
}
