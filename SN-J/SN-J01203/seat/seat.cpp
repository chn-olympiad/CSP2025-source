#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ans,k,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			w=n*m-i+1;
		}
	}
	if(w%(2*n)==0){
		cout<<n<<" "<<w/n;
		return 0;
	}
	if(w%(2*n)<=n){
		for(int i=0;i<n;i++){
			if(w%n==0){
				cout<<w/n<<" "<<n;
				return 0;
			}
			if(w%n==i){
				cout<<(w+n-i)/n<<" "<<w%n;
				return 0;
			}
		}
	}
	if(w%(2*n)>n){
		for(int i=0;i<n;i++){
			if(w%(2*n)-n==i){
				cout<<(w+n-i)/n<<" "<<n-i+1;
				return 0;
			}
		}
	}
}
