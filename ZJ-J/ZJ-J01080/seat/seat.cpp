#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r,n,m,m2,n2,R,pm;
    cin>>n>>m;
	int cc=n*m;
    int a[110];
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
        if(a[i]==R){
        	pm=i;
        	break;
		}
	}pm=n*m-pm;
	m2=(pm-1)/n+1;
	if(m2%2){
		n2=(pm-1)%n+1;
	}else{
		n2=(n-(pm-1)%n);
	}
	
    cout<<m2<<' '<<n2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
