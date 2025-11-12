#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,b[105][105];
int san(int x,int y,int z){
	if(x<y+z&&y<x+z&&z<y+x) return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int i=1;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			for(int z=1;z<=n;z++){
				if(x!=y&&x!=z&&y!=z&&san(a[x],a[y],a[z])==1){
					sum++;
					b[i][1]=a[x],b[i][2]=a[y],b[i][3]=a[z];
				}
			}
		}
	}
	printf("%d",sum/6%998244353);
	return 0;
}
