#include<bits/stdc++.h>
using namespace std;
int n,m,a[250];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int s=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m,j=1;i,j<=n*m;i--,j++){
		if(a[i]==s){
			s=j;
			break;
		}
	}
	if(s%n==0){
		if((s/n)%2==0)printf("%d %d",s/n,1);
		else printf("%d %d",s/n,n);
	}else{
		if((s/n+1)%2==0)printf("%d %d",s/n+1,n-s%n+1);
		else printf("%d %d",s/n+1,1+s%n-1);
	}
	return 0;
}
