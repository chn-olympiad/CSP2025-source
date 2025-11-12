#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,i=1,j=0,w=1;
	scanf("%d",&n);
	scanf("%d",&m);	
	scanf("%d",&a); 
	int b=a,c=n*m;
	while(i<c){
		scanf("%d",&a);
		i++;
		if(a>b) w++;
	}
		int e=w%n;
		if(e==0){
			int d=w/n;
			if(d%2==1) cout<<d<<' '<<n;
			else  cout<<d<<' '<<1;
			return 0;
		}
		int f=(w-e)/n;
		f+=1;
		if(f%2==1)cout<<f<<' '<<e;
		else cout<<f<<' '<<n-e+1;
	return 0;
}
