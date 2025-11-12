#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],c,r,p,q;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	p=a[0];
	sort(a,a+n*m);
	for(int i=n*m;i>0;i--){
		if(a[i]==p){
			q=n*m-i;
		} 
	}
		if(((q+n-q%n)/n)%2!=0&&q%n!=0||(q/n)%2!=0&&q%n==0){
			if(q%n!=0){
				cout<<(q+n-q%n)/n<<" "<<q%n;
			}else{
				cout<<q/n<<" "<<n;
			}
			
		}else if(q%n!=0){
			cout<<(q+n-q%n)/n<<" "<<n-q%n+1;
		}else{
			cout<<q/n<<" "<<n-q%n+1;
		}
	return 0;
}
