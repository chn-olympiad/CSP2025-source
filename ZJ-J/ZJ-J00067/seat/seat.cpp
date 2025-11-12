#include<bits/stdc++.h>
using namespace std;
int n,m,Rsc;
int seat[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n*m; i++){
		scanf("%d",&seat[i]);
	}
	Rsc=seat[1];
	sort(seat+1,seat+n*m+1);
	for(int i=1; i<=n*m; i++){
		int xxx=n*m-i+1;
		if(seat[i]==Rsc){
			if(xxx%m==0){
				if((xxx/m)%2==0) printf("%d %d",xxx/m,1);
				else printf("%d %d",xxx/m,m);
			}
			else{
				if((xxx/m+1)%2==0) printf("%d %d",xxx/m+1,m+1-(xxx%m));
				else printf("%d %d",xxx/m+1,xxx%m);
			}
			break;
		}
	}
	
	return 0;
}
