#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000],lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= n*m; i++){
		scanf("%d",&a[i]);
	}int as=a[1],r;
	
	sort(a+1, a+n*m+1);
	for(int i = 1; i <=(n*m)/2; i++) {
		swap(a[i],a[n*m-i+1]);
	}
	for(int i = 1; i <= n*m; i++) {
		if(a[i]=as){
			r = i;
		}
	}lie = (r)/(m);
	hang = (lie%2==0)?(r-1)%m+1:m-(r-1)%(m) ;
	
	printf("%d %d\n",lie, hang);
	
	return 0;
}
