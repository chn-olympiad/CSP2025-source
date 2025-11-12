#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],k=1,han,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1]) k++;
	}
	lie=(k-1)/n+1;
	han=k%n;
	if(lie%2==0){
		if(han==0) printf("%d %d",lie,1);
		else printf("%d %d",lie,n-han+1);
	}else{
		if(han==0) printf("%d %d",lie,n);
		else printf("%d %d",lie,han);
	}
	
	return 0;
}
