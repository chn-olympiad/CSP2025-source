#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],s,id=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]!=s){
			id++;
		}else{
			break;
		}
	}
	if(id<=n){
		cout<<1<<" "<<id;
	}else if(id>n){
		if(id%n==0){
			if((id/n)%2==0){
				cout<<id/n<<" "<<1;
			}else{
				cout<<id/n<<" "<<n;
			}
		}else{
			if((id/n)%2==0){
				cout<<(id/n)+1<<" "<<id-(id/n)*n;
			}else{
				cout<<(id/n)+1<<" "<<n-(id-(id/n)*n)+1;
			}
		}
		
	}
	return 0;
}
