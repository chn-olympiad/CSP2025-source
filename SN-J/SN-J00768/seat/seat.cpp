#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a[N+10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,h,l;
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
	}
	for(int i=2,t;i<=n*m;i++){
		if(a[i]>a[i-1]){
			t=a[i-1];
			a[i-1]=a[i];
			a[i]=t;
		}
	}
	for(int i=1;i<=100;i++){
		if(a[i]<r){
			double c=i;
			int l=ceil(c/n);
			int t=(int)c;
			if(l%2==1){
				if(n%t){
					h=t%n;
				}else{
					h=t;
				}	
			}else{
                h=n-t%n+1;
			}
			cout<<l<<" "<<h;
			break;
		}
	}
    return 0;
}

