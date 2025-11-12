#include<bits/stdc++.h>
using namespace std;
int n,m,w,x[10001],y[10001],ji;
struct node{
	int shu,bian;
}a[10001];
bool jj(node a,node b){
	return a.shu>b.shu;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i].shu;
    	a[i].bian=i;
	}
	w=a[1].shu;
	sort(a+1,a+n*m+1,jj);
	for(int i=1;i<=n*m;i++){
	    if(((i-1)/n+1)%2==1){
	    	//y[i]=(i/n+i%n);
	    	y[i]=i%(n*2);
	    	x[i]=(i-1)/n+1;
		}else{
			x[i]=(i-1)/n+1;
			y[i]=n-i%n+1;
			if(y[i]>n){
				y[i]%=n;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].shu==w){
			ji=i;
			break;
		}
	}
	
	cout<<x[ji]<<' '<<y[ji];return 0;
    fclose(stdin);
    fclose(stdout);
   return 0; 
    
}
