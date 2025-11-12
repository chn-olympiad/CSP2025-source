#include<bits/stdc++.h>
using namespace std;
int n,m,x,a,maxx=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&x);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a);
		if(a>x)maxx++;
	}
	int lie=maxx/n+1,hang;
	if(lie%2==1){
		if((maxx+1)%n==0)hang=n;
		else hang=(maxx+1)%n;
	}
	else{
		if((maxx+1)%n==0){
			hang=1;
		}
		else{
			hang=n-(maxx+1)%n+1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}