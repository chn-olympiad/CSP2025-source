#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[105],sum,r,l,h;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=i;j++){
            if(a[j]<a[j+1]){
                sum=a[j];
                a[j]=a[j+1];
                a[j+1]=sum;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
        	if(i%n==0){
            	l=i/n;
            	if(l%2==0){
                	h=n-(i-i/n*n);
            	}
            	else{
                	h=n;
            	}
			}
			else{
            	l=i/n+1;
            	if(l%2==0){
                	h=n-(i-i/n*n)+1;
            	}
            	else{
                	h=i-i/n*n;
            	}
			}
		}
    }
    cout<<l<<" "<<h;
    return 0;
}


