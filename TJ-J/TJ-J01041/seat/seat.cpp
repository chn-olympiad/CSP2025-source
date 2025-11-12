#include<bits/stdc++.h>
using namespace std;
int n,m,xm;
int cj[105];
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&xm);
	cj[1]=xm;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&cj[i]);
	}
	sort(cj+1,cj+n*m+1);
	reverse(cj+1,cj+n*m+1);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				if(cj[cnt]==xm){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(cj[cnt]==xm){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
