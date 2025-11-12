#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N],sc,cnt;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==sc){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==sc){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
