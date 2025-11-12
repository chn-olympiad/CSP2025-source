#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,t,p,d,e;
	cin>>n>>m;
	t=n*m;
    int a[t];
    int b[n][m];
    for(int i=1;i<=t;i++){
    	cin>>a[i];
	}
	d=a[1];
    for(int i=1;i<=t;i++){
    	for(int j=1;j<=t;j++){
    		if(a[i]<a[i+1]){
    			p=a[i];
    			a[i]=a[i+1];
    			a[i+1]=p;
			}
		}
	}
	e=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=a[e];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==d){
				c=i;
				r=j;
				break;
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
