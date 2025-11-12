#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],l=0,w,c=0,r=0,id=0;;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		l++;
	}
	int R=a[0];
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		id++;
		if(a[i]==R){
			w=id;
		}
	}	
	if(w%n==0){
		if((w/n)%2==1){
			c=w/n;
			r=n;
		}else if((w/n)%2==0){
			c=w/n;
			r=1;
		}
	}else{
		if((w/n)%2==0){		
			c=(w/n)+1;
			r=w%n;
		}else if((w/n)%2==1){
			c=(w/n)+1;
			r=n-(w%n)+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
