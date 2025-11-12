#include<bits/stdc++.h>
using namespace std;
const int N=1135;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[(i-1)*m+j]);
			if(a[(i-1)*m+j]>a[1])cnt++;
		}
	}
	int c=cnt/m,r=cnt%m;
	if(c&1){
		r=m-r-1;
	}
	printf("%d %d\n",c+1,r+1);
	return 0;
}